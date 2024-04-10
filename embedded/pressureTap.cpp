#include "pressureTap.h"
#include "core_pins.h"


pressureTap::pressureTap(int pinNum, int pinLoc, TI_TCA9548A *multiplexer, AllSensors_DLHR_L02D_8 *pSensor, MCP23017 *mcp) {
	pinNumber = pinNum;
	pinLocation = pinLoc;
	pressureReading = 0;
	temperatureReading = 0;
	pressureSensor = pSensor;
	ioExpander = mcp;
	samplePeriod = static_cast<int>(1.0f/static_cast<float>(sampleFrequency)*1000.0f); // ms
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
  delay(samplePeriod);
  bool condition = false;
  while(condition == false) {
	  condition = pressureSensor->readDataAsynchro(AllSensors_DLHR::AVERAGE16);
  }
  pressureReading = pressureSensor->pressure;
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
