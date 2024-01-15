#ifndef PRESSURE_BARO_H
#define PRESSURE_BARO_H

#include <stdlib.h>

struct MemoryStruct {
	char *memory;
	size_t size;
};

/** 
 * @brief
 * 	Callback function that gets used by libcurl to store webpage contents
 *
 * 	@param 
 */
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

/**
	* @brief
	* 	Gets the current atmospheric pressure from this webpage:
	* 	https://www.enet.umn.edu/auto-generated/pressure/
	* 
	* @returns The current barometric pressure in Pascals. -100 indicates that there was an error
	* getting the value. A negative number other than -100 means that the measurement is uncertain.
	* 
	*/
double FetchBaroPressure();

#endif
