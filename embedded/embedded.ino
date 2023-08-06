#include "Wire.h"
#include "pressureTap.h"
#include "src/ams5812/src/ams5812.h"
#include "src/arduino-mcp23017/src/MCP23017.h"
#include "src/ArduinoSerialCommand/SerialCommand.h"

// MCP23017 //
const uint8_t MCP_addr = 0x20;
MCP23017 mcp = MCP23017(MCP_addr, Wire);


// AMS 5812 //
const uint8_t pSensorTaps_addr = 0x04;
const uint8_t pSensorAspd_addr = 0x05;
bfs::Ams5812 pSensorTaps(&Wire, pSensorTaps_addr, bfs::Ams5812::AMS5812_0003_D);
bfs::Ams5812 pSensorAspd(&Wire, pSensorAspd_addr, bfs::Ams5812::AMS5812_0003_D);

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

pressureTap valveArray[] = {
	pressureTap(sol1_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol2_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol3_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol4_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol5_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol6_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol7_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol8_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol9_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol10_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol11_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol12_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol13_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol14_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol15_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol16_pinMCP, 1, &pSensorTaps, &mcp),
	pressureTap(sol17_pin, 0, &pSensorTaps, &mcp),
	pressureTap(sol18_pin, 0, &pSensorTaps, &mcp),
	pressureTap(sol19_pin, 0, &pSensorTaps, &mcp),
	pressureTap(sol20_pin, 0, &pSensorTaps, &mcp)
};

float pressureTapSampleFreq = 1; // Hz

SerialCommand sCmd;

void ScanPressureTaps() {
	Serial.print("<1");
	for (int i = 0; i < 20; i++){
		valveArray[i].UpdatePressure();
		Serial.print(",");
		Serial.print(valveArray[i].GetPressure());
	}
	Serial.println(">");
}

void GetAirspeed() {
	float deltaP = pSensorAspd.pres_pa();
	float aspd = sqrt(2.0f*deltaP / 1.225f);
	Serial.print("<2,");
	Serial.print(aspd);
	Serial.println(">");
}

void unrecognized()
{
  Serial.println("What?"); 
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(100000);
  if (!pSensorTaps.Begin()) {
    Serial.println("Pressure sensor 1 failed to initialize");
  }
  if (!pSensorAspd.Begin()) {
    Serial.println("Pressure sensor 2 failed to initialize");
  }
  mcp.begin();
  // Configure all pins on MCP as outputs
  mcp.portMode(MCP23017Port::A, 0);
  mcp.portMode(MCP23017Port::B, 0);
  // Configure remaining output pins
  for (int i = 16; i < 20; i++) {
		valveArray[i].ConfigureTeensyPinForOutput();
  }
	
	// Commands
	sCmd.addCommand("SCANTAPS", ScanPressureTaps);
	//sCmd.addCommand("!SETSPEEDAUTO", AutoSpeedControlSet);
	//sCmd.addCommand("!SETPOWER", SetFanPower);
  sCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?") 

  Serial.println("Finished setup");
}

void loop() {
	sCmd.readSerial();
	//GetAirspeed();
}

