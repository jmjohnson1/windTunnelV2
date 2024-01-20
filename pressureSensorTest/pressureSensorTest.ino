#include "DLHR.h"
#include <SPI.h>

const uint8_t P1_PIN = 1;
const uint8_t P2_PIN = 2;
DLHR p1(1000000, P1_PIN);
DLHR p2(1000000, P2_PIN);

float temp1 = 0.0f;
float temp2 = 0.0f;
float pres1 = 0.0f;
float pres2 = 0.0f;

void setup() {
	Serial.begin(9600);
	while(!Serial);

	Serial.println("Initializing...");
	pinMode(P1_PIN, OUTPUT);
	pinMode(P2_PIN, OUTPUT);

	SPI.begin();
	Serial.println("Initialized!");
}

void loop() {
	// Take a measurement from p1 and display the pressure and temperature to serial
	p1.NewMeasurement(MeasurementType::AVERAGE16);
	if (p1.ReadData() == 0) {
		Serial.println("Result:");
		pres1 = p1.GetPressure();
    temp1 = p1.GetTemperature();
		Serial.print("Pressure: ");
		Serial.println(pres1, 4);
		Serial.print("Temperature: ");
		Serial.println(temp1, 4);
	} else {
		Serial.println("There was an error :'(");
	}
	Serial.println("Done.");
}
