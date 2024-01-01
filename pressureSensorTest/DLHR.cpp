#include "DLHR.h"
#include "core_pins.h"
#include <cstdint>

DLHR::DLHR(uint32_t speed, uint8_t cs) {
	settings_ = SPISettings(speed, MSBFIRST, SPI_MODE0);
  chipSelect_ = cs;
	digitalWriteFast(chipSelect_, HIGH);
	pressureResolutionMask = ~(((uint32_t) 1 << (FULLSCALE_RESOLUTION - 18)) - 1); // 11111111111111111111111111000000
	temperatureResolutionMask = ~(((uint32_t) 1 << (FULLSCALE_RESOLUTION - 16)) - 1); // 11111111111111111111111100000000
	
	Serial.println("Masks:");
	Serial.print("pressureResolutionMask: ");
	Serial.println(pressureResolutionMask, BIN);
	Serial.print("temperatureResolutionMask: ");
	Serial.println(temperatureResolutionMask, BIN);

}

void DLHR::NewMeasurement(MeasurementType command) {
	Serial.print("Command: ");
	Serial.println(command);
	digitalWriteFast(chipSelect_, LOW);
	SPI.beginTransaction(settings_);
	SPI.transfer((uint8_t) command);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	digitalWriteFast(chipSelect_, HIGH);
	SPI.endTransaction();
}

int DLHR::ReadData(bool wait) {
try_again:
	Serial.println("Reading");
	SPI.beginTransaction(settings_);
	digitalWriteFast(chipSelect_, LOW);

	// First byte is status
	uint8_t status = SPI.transfer(0xF0);
	Serial.print("Status: ");
	Serial.println(status, BIN);

	// Check for errors. Return 2 if there are errors.
	if (isError(status)) {
		digitalWriteFast(chipSelect_, HIGH);
		SPI.endTransaction();
		goto error;
	}
	
	// Try again if device is busy and wait is true. If wait is false, return 1.
	if (isBusy(status)) {
		digitalWriteFast(chipSelect_, HIGH);
		SPI.endTransaction();
		if (wait) {
			delayMicroseconds(100);
			goto try_again;
		}
		goto busy;
	}

	// Reading the 24-bit pressure in 1byte increments and storing it in raw_p_. MSB first. This is
	// not the safest way to do this.
	*((uint8_t *)(&raw_p_) + 2) = SPI.transfer(0x00);
	*((uint8_t *)(&raw_p_) + 1) = SPI.transfer(0x00);
	*((uint8_t *)(&raw_p_)) = SPI.transfer(0x00);
	Serial.print("Raw pressure: ");
	Serial.println(raw_p_, BIN);

	// Reading 24-bit temperature
	*((uint8_t *)(&raw_t_) + 2) = SPI.transfer(0x00);
	*((uint8_t *)(&raw_t_) + 1) = SPI.transfer(0x00);
	*((uint8_t *)(&raw_t_)) = SPI.transfer(0x00);
	Serial.print("Raw temperature: ");
	Serial.println(raw_t_, BIN);

	digitalWriteFast(chipSelect_, HIGH);
	SPI.endTransaction();

	pressure_ = PressureTransferFunction(raw_p_ & pressureResolutionMask);
	temperature_ = TemperatureTransferFunction(raw_t_ & temperatureResolutionMask);
	
	return 0;

busy:
	return 1;

error:
	return 2;
}

float DLHR::PressureTransferFunction(uint32_t digitalPressure) {
	Serial.print("Digital pressure: ");
	Serial.println(digitalPressure, BIN);
	float pressure = 1.25f * (digitalPressure - digitalOffset)/static_cast<float>(FULLSCALE_REF) * fullScaleSpan;
	return pressure;
}

float DLHR::TemperatureTransferFunction(uint32_t digitalTemperature) {
	Serial.print("Digital temperature: ");
	Serial.println(digitalTemperature, BIN);
	float temperature = (digitalTemperature*125.0f)/static_cast<float>(FULLSCALE_REF) - 40.0f;
	return temperature;
}
