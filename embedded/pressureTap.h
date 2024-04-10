#ifndef PRESSURE_TAP_H
#define PRESSURE_TAP_H

#include <TI_TCA9548A.h> // I2C multiplexer
#include "src/arduino-mcp23017/src/MCP23017.h"
//#include "src/ams5812/src/ams5812.h"
//#include "src/ams5915/src/ams5915.h"
#include "src/DLHR/src/AllSensors_DLHR.h"  // Pressure sensors

class pressureTap {
public:
	pressureTap(int pinNum, int pinLoc, TI_TCA9548A *multiplexer, AllSensors_DLHR_L02D_8 *pSensor, MCP23017 *mcp);

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
	int sampleFrequency=1;
	int samplePeriod;
	AllSensors_DLHR_L02D_8 *pressureSensor = nullptr;
	MCP23017 *ioExpander = nullptr;
	TI_TCA9548A *tca9548a = nullptr;
	const uint8_t multiplexerChannel = 0; // Defines which pin the pressure sensor for the taps is connected to on the multiplexer
};

#endif // PRESSURE_TAP_H
