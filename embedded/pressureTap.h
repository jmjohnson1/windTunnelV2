#ifndef PRESSURE_TAP_H
#define PRESSURE_TAP_H

#include "src/arduino-mcp23017/src/MCP23017.h"
#include "src/ams5812/src/ams5812.h"

class pressureTap {
public:
	pressureTap(int pinNum, int pinLoc, bfs::Ams5812 *pSensor, MCP23017 *mcp);

	void UpdatePressure();
	void UpdateTemperature();
	float GetPressure();
	float GetTemperature();
	void SetPinNumber(int pinNum);
	void SetPinLocation(int pinLoc);
	void ConfigureTeensyPinForOutput();
	

private:
	uint8_t pinNumber;
	uint8_t pinLocation; // 0 for Teensy pin, 1 for pin on MCP23017
	float pressureReading;
	float temperatureReading;
	bfs::Ams5812 *pressureSensor;
	MCP23017 *ioExpander;

};

#endif // PRESSURE_TAP_H
