/*
* Gets the current barometric pressure in millibars from
* http://www.enet.umn.edu/auto-generated/pressure/
*/
#include "getPressure.h"
#include <stdio.h>
#include <string.h>
#include <pcre2posix.h>

#include <curl/curl.h>


static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}

double FetchBaroPressure(){
  CURL *curl_handle;
  CURLcode res;

	double pressure_pa = -100.0;
 
  struct MemoryStruct chunk;
 
  chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
  chunk.size = 0;    /* no data at this point */
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* init the curl session */
  curl_handle = curl_easy_init();
  /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.enet.umn.edu/auto-generated/pressure/");
  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  /* we pass our 'chunk' struct to the callback function */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
  /* some servers do not like requests that are made without a user-agent
     field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  /* get the data */
  res = curl_easy_perform(curl_handle);
 
  /* check for errors */
  if(res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
  }
  else { /* No errors */
		/* Using regex to get the pressure from the HTML text */
		regex_t regex;
		char *regExpr = "([0-9]+\\.[0-9]+)[[:space:]]+millibar";
		int returnStatus;

		regmatch_t match[2];
		char *matchedExpr;
		int matchSize;

        returnStatus = pcre2_regcomp(&regex, regExpr, REG_EXTENDED);
		if (returnStatus) {
			fprintf(stderr, "Could not compile regex\n");
			exit(pressure_pa);
		}

		/* Execute regular expression */
        returnStatus = pcre2_regexec(&regex, chunk.memory, 2, match, 0);
		if (!returnStatus) { /* Match */
			/* Store the match */
			matchSize = (int)(match[1].rm_eo - match[1].rm_so);
			matchedExpr = (char*)malloc(matchSize * sizeof(char));
			strncpy(matchedExpr, chunk.memory + match[1].rm_so, matchSize);
			pressure_pa = atof(matchedExpr)*100.0; /* Server gives pressure in millibars */
			free(matchedExpr);

		}
		else if (returnStatus == REG_NOMATCH) { /* No match */
			puts("Unable to parse the barometric pressure from the ENet webpage");
		}
		else { /* Collector for any other error */
			fprintf(stderr, "Failed to grab barometric pressure\n");
		}

		/* Free memory allocated to the pattern buffer by regcomp() */
        pcre2_regfree(&regex);
  }
 
  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);
  free(chunk.memory);
 
  /* we are done with libcurl, so clean it up */
  curl_global_cleanup();
 
  return pressure_pa;
}
