#include "pressureTap.h"
#include "core_pins.h"


pressureTap::pressureTap(int pinNum, int pinLoc, TI_TCA9548A *multiplexer, AllSensors_DLHR_L02D_8 *pSensor, MCP23017 *mcp, int sampleFreq = 1) {
	pinNumber = pinNum;
	pinLocation = pinLoc;
	pressureReading = 0;
	temperatureReading = 0;
	pressureSensor = pSensor;
	ioExpander = mcp;
	sampleFrequency = sampleFreq;
	samplePeriod = static_cast<int>(1.0f/static_cast<float>(sampleFreq)*1000.0f); // ms
	tca9548a = multiplexer;
}

void pressureTap::UpdatePressure() {
  uint32_t startTime = millis();
  // Open valve
	if (pinLocation) {
		ioExpander->digitalWrite(pinNumber, HIGH);
	} else {
		digitalWrite(pinNumber, HIGH);
	}
  // Read data
	float runningSum = 0;
  	int numberSampled = 0;
	tca9548a->selectChannel(multiplexerChannel);
  	while(millis() - startTime < samplePeriod) {
	bool condition = pressureSensor->readDataAsynchro();
	if (condition) {
		runningSum += pressureSensor->pressure;
		numberSampled++;
	}
  }
  pressureReading = runningSum / static_cast<float>(numberSampled);
  // Close valve
	if (pinLocation) {
		ioExpander->digitalWrite(pinNumber, LOW);
	} else {
		digitalWrite(pinNumber, LOW);
	}
}

float pressureTap::GetPressure() {
	return pressureReading;
}

void pressureTap::UpdateTemperature() {
	tca9548a->selectChannel(multiplexerChannel);
	bool condition = pressureSensor->readDataAsynchro();
	if (condition) {
		temperatureReading = pressureSensor->temperature;
	} else {
		temperatureReading = 0;
	}
}

float pressureTap::GetTemperature() {
	return temperatureReading;
}

void pressureTap::SetPinNumber(int pinNum) {
	pinNumber = pinNum;
}

void pressureTap::SetPinLocation(int pinLoc) {
	pinLocation = pinLoc;
}

void pressureTap::ConfigureTeensyPinForOutput() {
	if (pinLocation == 0) {
		pinMode(pinNumber, OUTPUT);
	}
}
