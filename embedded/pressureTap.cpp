#include "pressureTap.h"
#include "core_pins.h"

pressureTap::pressureTap(int pinNum, int pinLoc, bfs::Ams5915 *pSensor, MCP23017 *mcp, int sampleFreq = 1) {
	pinNumber = pinNum;
	pinLocation = pinLoc;
	pressureReading = 0;
	temperatureReading = 0;
	pressureSensor = pSensor;
	ioExpander = mcp;
  sampleFrequency = sampleFreq;
  samplePeriod = static_cast<int>(1.0f/static_cast<float>(sampleFreq)*1000.0f); // ms
}

void pressureTap::UpdatePressure() {
	if (pinLocation) {
		ioExpander->digitalWrite(pinNumber, HIGH);
	} else {
		digitalWrite(pinNumber, HIGH);
	}
	delay(samplePeriod);
	pressureReading = pressureSensor->pres_pa();
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
	temperatureReading = pressureSensor->die_temp_c();
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
