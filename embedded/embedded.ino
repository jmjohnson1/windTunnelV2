#include <Wire.h>
#include <Servo.h>

#include <TI_TCA9548A.h> // I2C multiplexer

#include "src/ams5915/src/ams5915.h"
#include "src/arduino-mcp23017/src/MCP23017.h" // IO expander
#include "src/ArduinoSerialCommand/SerialCommand.h" // Serial command handler
#include "src/DLHR/src/AllSensors_DLHR.h"  // Pressure sensors

#include "pressureTap.h"

#define MSG_ID_AIRSPEED 2
#define MSG_ID_PRESSURE_TAP_READINGS 1
#define MAX_ARG_LENGTH 10

#define TCAADDR 0x70

// MCP23017 //
const uint8_t MCP_addr = 0x20;
MCP23017 mcp = MCP23017(MCP_addr, Wire);

// TCA9548A //
TI_TCA9548A tca9548a(&Wire);

// DLHR //
AllSensors_DLHR_L02D_8 pSensorAspd(&Wire);
AllSensors_DLHR_L02D_8 pSensorTaps(&Wire);
float meanBias_pAspd = 0.0f;
float meanBias_pTaps = 0.0f;
float density = 1.225f;

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
	pressureTap(sol1_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol2_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol3_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol4_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol5_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol6_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol7_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol8_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol9_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol10_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol11_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol12_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol13_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol14_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol15_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol16_pinMCP, 1, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol17_pin, 0, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol18_pin, 0, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol19_pin, 0, &tca9548a, &pSensorTaps, &mcp),
	pressureTap(sol20_pin, 0, &tca9548a, &pSensorTaps, &mcp)
};

// Fans
const uint8_t fan1Pin = 4;
const uint8_t fan2Pin = 5;
const uint8_t fan3Pin = 6;

SerialCommand sCmd;

void ScanPressureTaps() {
	Serial.print("<");
  Serial.print(MSG_ID_PRESSURE_TAP_READINGS);
	for (int i = 0; i < 20; i++){
		valveArray[i].UpdatePressure();
		Serial.print(",");
		Serial.print(valveArray[i].GetPressure() - meanBias_pTaps);
	}
	Serial.println(">");
	Serial.println("Done");
}

void GetAirspeed() {
  static uint8_t numberSamples = 10;
  float runningSum = 0;
  tca9548a.selectChannel(1);
  for (int i = 0; i < numberSamples; i++) {
	bool condition = pSensorAspd.readDataAsynchro();
	if (condition) {
		runningSum += (pSensorAspd.pressure - meanBias_pAspd);
	}
  }
  float deltaP = runningSum / static_cast<float>(numberSamples);
	float aspd = sqrt(2.0f*deltaP / density);
  if (deltaP < 0.0f) {
    aspd = 0.0f;
  }
	Serial.print("<");
  Serial.print(MSG_ID_AIRSPEED);
  Serial.print(",");
	Serial.print(aspd);
  Serial.print(",");
  Serial.println(deltaP);
	Serial.println(">");
}

void SetFanPower() {
  char *arg;
	char *inputBuffer[MAX_ARG_LENGTH];
	int msgLength = 0;
	int i = 0;
	while ((arg = sCmd.next()) != nullptr) {
		if (msgLength < MAX_ARG_LENGTH) {
		msgLength++;
		inputBuffer[i] = arg;
		i++;
		}
	}
	// Let's make sure any remaining space in the buffer is whitespace
	if (msgLength < MAX_ARG_LENGTH) {
		for (int i = msgLength; i < MAX_ARG_LENGTH; i++) {
			inputBuffer[i] = " ";
		}
	}

	int power = atoi(*inputBuffer);
  int powerScaled = 0;
	// If the power settings is below 10%, use only one fan at power + 10%
	if (power < 10 && power > 0) {
		powerScaled = map(power+10, 0, 100, 0, 255);
		analogWrite(fan1Pin, powerScaled);
    analogWrite(fan2Pin, LOW);
	} else {
		// Need to scale this to be bewteen 0 and 255
		powerScaled = map(power, 0, 100, 0, 255);
		analogWrite(fan1Pin, powerScaled);
		analogWrite(fan2Pin, powerScaled);
	}
  Serial.println(powerScaled);
	Serial.println("Done");
}

void SetSmokeFanPower() {
  char *arg;
	char *inputBuffer[MAX_ARG_LENGTH];
	int msgLength = 0;
	int i = 0;
	while ((arg = sCmd.next()) != nullptr) {
		if (msgLength < MAX_ARG_LENGTH) {
		msgLength++;
		inputBuffer[i] = arg;
		i++;
		}
	}
	// Let's make sure any remaining space in the buffer is whitespace
	if (msgLength < MAX_ARG_LENGTH) {
		for (int i = msgLength; i < MAX_ARG_LENGTH; i++) {
			inputBuffer[i] = " ";
		}
	}

	int power = atoi(*inputBuffer);

  // Need to scale this to be bewteen 0 and 180
  int powerScaled = map(power, 0, 100, 0, 255);
  analogWrite(fan3Pin, powerScaled);
  Serial.println(powerScaled);
	Serial.println("Done");
}

void unrecognized()
{
  Serial.println("What?"); 
}

float tarePSensor(AllSensors_DLHR_L02D_8 *sensor, uint8_t channel) {
	// int numSamples = 1000;
	// float sum = 0;
	// tca9548a.selectChannel(channel);
	// for (int i = 0; i < numSamples; i++) {
	// 	bool condition = sensor->readDataAsynchro();
	// 	if (condition) {
	// 		sum += sensor->pressure;
	// 	}
	// }
	// float meanBias = sum/numSamples;

  bool condition = false;
  tca9548a.selectChannel(channel);
  while(!condition) {
    condition = sensor->readDataAsynchro(AllSensors_DLHR::AVERAGE16);
  }

  float meanBias = sensor->pressure;
	
  Serial.print(meanBias);
	return meanBias;
}

void TareAllPSensors() {
	meanBias_pAspd = tarePSensor(&pSensorAspd, 1);
	meanBias_pTaps = tarePSensor(&pSensorTaps, 0);
}

void SetDensity() {
  char *arg;
	char *inputBuffer[MAX_ARG_LENGTH];
	int msgLength = 0;
	int i = 0;
	while ((arg = sCmd.next()) != nullptr) {
		if (msgLength < MAX_ARG_LENGTH) {
		msgLength++;
		inputBuffer[i] = arg;
		i++;
		}
	}
	// Let's make sure any remaining space in the buffer is whitespace
	if (msgLength < MAX_ARG_LENGTH) {
		for (int i = msgLength; i < MAX_ARG_LENGTH; i++) {
			inputBuffer[i] = " ";
		}
	}

	density = atof(*inputBuffer);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Initializing...");
  Wire.begin();
  Wire.setClock(100000);
	// Wait 100 milliseconds
  delay(100);

  pSensorAspd.setPressureUnit(AllSensors_DLHR::PressureUnit::PASCAL);
  pSensorTaps.setPressureUnit(AllSensors_DLHR::PressureUnit::PASCAL);

  mcp.begin();
  // Configure all pins on MCP as outputs
  mcp.portMode(MCP23017Port::A, 0);
  mcp.portMode(MCP23017Port::B, 0);
  // Configure remaining output pins
  for (int i = 16; i < 20; i++) {
		valveArray[i].ConfigureTeensyPinForOutput();
  }

	TareAllPSensors();
	
	// Commands
	sCmd.addCommand("!SCANTAPS", ScanPressureTaps);
	//sCmd.addCommand("!SETSPEEDAUTO", AutoSpeedControlSet);
	sCmd.addCommand("!SETPOWER", SetFanPower);
  sCmd.addCommand("!SETSMOKE", SetSmokeFanPower);
	sCmd.addCommand("!TARE", TareAllPSensors);
	sCmd.addCommand("!SETDENSITY", SetDensity);
  sCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?") 

	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, HIGH);

  analogWrite(fan1Pin, LOW);
  analogWrite(fan2Pin, LOW);
  analogWrite(fan3Pin, LOW);

  Serial.println("Setup complete");
}

void loop() {

	sCmd.readSerial();
	GetAirspeed();

  delay(100);
}
