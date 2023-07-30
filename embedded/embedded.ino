#include "src/arduino-mcp23017/src/MCP23017.h"
#include "src/ams5812/src/ams5812.h"
#include "commands.h"
#include "Wire.h"

// MCP23017 //
const uint8_t MCP_addr = 0x00;
MCP23017 mcp = MCP23017(MCP_addr);

// Solenoid valve pins //
const uint8_t sol1_pinMCP = 0;
const uint8_t sol2_pinMCP = 1;
const uint8_t sol3_pinMCP = 2;
const uint8_t sol4_pinMCP = 3;
const uint8_t sol5_pinMCP = 4;
const uint8_t sol6_pinMCP = 5;
const uint8_t sol7_pinMCP = 6;
const uint8_t sol8_pinMCP = 7;
const uint8_t sol9_pinMCP = 8;
const uint8_t sol10_pinMCP = 9;
const uint8_t sol11_pinMCP = 10;
const uint8_t sol12_pinMCP = 11;
const uint8_t sol13_pinMCP = 12;
const uint8_t sol14_pinMCP = 13;
const uint8_t sol15_pinMCP = 14;
const uint8_t sol16_pinMCP = 15;
const uint8_t sol17_pin = 3;
const uint8_t sol18_pin = 2;
const uint8_t sol19_pin = 1;
const uint8_t sol20_pin = 0;

uint8_t pinArray[20] = {
	sol1_pinMCP,
	sol2_pinMCP,
	sol3_pinMCP,
	sol4_pinMCP,
	sol5_pinMCP,
	sol6_pinMCP,
	sol7_pinMCP,
	sol8_pinMCP,
	sol9_pinMCP,
	sol10_pinMCP,
	sol11_pinMCP,
	sol12_pinMCP,
	sol13_pinMCP,
	sol14_pinMCP,
	sol15_pinMCP,
	sol16_pinMCP,
	sol17_pin,
	sol18_pin,
	sol19_pin,
	sol20_pin
};

float pressureTapSampleFreq = 1; 	// Hz

// AMS 5812 //
const uint8_t pSensor1_addr = 0x04;
const uint8_t pSensor2_addr = 0x05;
bfs::Ams5812 pSensor1(&Wire, pSensor1_addr, bfs::Ams5812::AMS5812_0003_D);
bfs::Ams5812 pSensor2(&Wire, pSensor2_addr, bfs::Ams5812::AMS5812_0003_D);

// Analog Inputs //

void setup() {
	Serial.begin(9600);
	Wire.begin();
	Wire.setClock(400000); // Fast mode
	// if (!pSensor1.Begin()) {
	// 	Serial.println("Pressure sensor 1 failed to initialize");
	// }
	// if (!pSensor2.Begin()) {
	// 	Serial.println("Pressure sensor 2 failed to initialize");
	// }
  Serial.println("Before mcp");
	mcp.begin();
  Serial.println("After mcp.");
	// Configure all pins on MCP as outputs
	mcp.portMode(MCP23017Port::A, 0);
	mcp.portMode(MCP23017Port::B, 0);
	// Configure remaining output pins
	for (int i = 16; i < 20; i++) {
		pinMode(pinArray[i], OUTPUT);
	}
  Serial.println("Finished setup");
}

void loop() {
	scanPressureTaps();
  Serial.println("Scan Complete");
}

void scanPressureTaps() {
	for (int i = 0; i < 20; i++) {
    Serial.println(i);
		if (i > 15) {
			digitalWrite(pinArray[i], 1);
			delay(1.0f/pressureTapSampleFreq*1000.0f);
			digitalWrite(pinArray[i], 0);
		} else {
			mcp.digitalWrite(pinArray[i], 1);
			delay(1.0f/pressureTapSampleFreq*1000.0f);
			mcp.digitalWrite(pinArray[i], 0);
		}
	}
}
