#ifndef DLHR_H
#define DLHR_H

#include <stdint.h>
#include <SPI.h>
#include <Arduino.h>

enum MeasurementType {
	/*
	* The sensor supports different measurement modes. It can take a single measurement or and average
	* of up to 16 measurements on command. Page 3 of the datasheet gives the min, typ, and max times
	* needed for each of these processes to complete.
	*/
	SINGLE    = 0xAA,  // max 4.1 ms
	AVERAGE2  = 0xAC,  // max 8.0 ms
	AVERAGE4  = 0xAD,  // max 15.7 ms
	AVERAGE8  = 0xAE,  // max 31.1 ms
	AVERAGE16 = 0xAF,  // max 61.9 ms
};

enum StatusFlags {
	/*
	 * Status byte definition given on page 8 of the datasheet. The most significant bit should always
	 * be zero.
	*/
	ALWAYS0 = 1<<7,
	POWER_ON = 1<<6,
	BUSY = 1<<5,
	MODE = 1<<4 | 1<<3,
	MEM_ERROR = 1<<2,
	CONFIGURATION = 1<<1,
	ALU_ERROR = 1<<0,
};

class DLHR {
public:
	DLHR(uint32_t speed, uint8_t cs);
	void NewMeasurement(MeasurementType = MeasurementType::SINGLE);
	int ReadData(bool wait = true);

	float GetTemperature() {return temperature_;}
	float GetPressure() {return pressure_;}

private:
	float PressureTransferFunction(uint32_t digitalPressure);
	float TemperatureTransferFunction(uint32_t digitalTemperature);
	
	/*
	 * Returns true if the status byte contains a memory error and/or an ALU error flag
	*/
	bool isError(uint8_t status) {
		return (status & (StatusFlags::MEM_ERROR | StatusFlags::ALU_ERROR)) != 0;
	}

	/*
	* Returns true if the status byte indicates that the device is busy
	*/
	bool isBusy(uint8_t status) {
		return (status & StatusFlags::BUSY) != 0;
	}

	uint32_t raw_p_ = 0;
	uint32_t raw_t_ = 0;
	float temperature_ = 0.0f;
	float pressure_ = 0.0f;
	uint32_t pressureResolutionMask;
	uint32_t temperatureResolutionMask;

	// Valid for all DLHR
	const uint32_t FULLSCALE_RESOLUTION = 24;
	const uint32_t FULLSCALE_REF = 1 << FULLSCALE_RESOLUTION; // 2^24

	// Valid for our specific type of sensors
	float digitalOffset = 0.5f*FULLSCALE_REF;
	float fullScaleSpan = 2.0f*(497.68f); // Pascals
	
	// SPI
	SPISettings settings_;
	uint8_t chipSelect_;
};

#endif
