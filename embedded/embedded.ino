#include "Wire.h"
#include "Servo.h"

#include "src/ams5915/src/ams5915.h"
#include "src/arduino-mcp23017/src/MCP23017.h"
#include "src/ArduinoSerialCommand/SerialCommand.h"

#include "pressureTap.h"

#define MSG_ID_AIRSPEED 2
#define MSG_ID_PRESSURE_TAP_READINGS 1

// MCP23017 //
const uint8_t MCP_addr = 0x20;
MCP23017 mcp = MCP23017(MCP_addr, Wire);

// AMS 5915 //
const uint8_t pSensorTaps_addr = 0x22;
const uint8_t pSensorAspd_addr = 0x23;
bfs::Ams5915 pSensorTaps(&Wire, pSensorTaps_addr, bfs::Ams5915::AMS5915_0020_D_B);
bfs::Ams5915 pSensorAspd(&Wire, pSensorAspd_addr, bfs::Ams5915::AMS5915_0020_D_B);
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
  pSensorAspd.Read();
  static uint8_t numberSamples = 10;
  float runningSum = 0;
  for (int i = 0; i < numberSamples; i++) {
    runningSum += pSensorAspd.pres_pa() - meanBias_pAspd;
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
	char *inputs[3];
	int i = 0;
	while ((arg = sCmd.next())) {
		inputs[i] = arg;
	}
	int power = atoi(*inputs);
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
	char *inputs[3];
	int i = 0;
	while ((arg = sCmd.next())) {
		inputs[i] = arg;
	}
	int power = atoi(*inputs);

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

float tarePSensor(bfs::Ams5915 *sensor) {
	int numSamples = 1000;
	float sum = 0;
	for (int i = 0; i < numSamples; i++) {
		sensor->Read();
		sum += sensor->pres_pa();
	}
	float meanBias = sum/numSamples;
	return meanBias;
}

void TareAllPSensors() {
	meanBias_pAspd = tarePSensor(&pSensorAspd);
	meanBias_pTaps = tarePSensor(&pSensorTaps);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Initializing...");
  Wire.begin();
  Wire.setClock(100000);
	// Wait 100 milliseconds
	delay(100);
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

	TareAllPSensors();
	
	// Commands
	sCmd.addCommand("!SCANTAPS", ScanPressureTaps);
	//sCmd.addCommand("!SETSPEEDAUTO", AutoSpeedControlSet);
	sCmd.addCommand("!SETPOWER", SetFanPower);
  sCmd.addCommand("!SETSMOKE", SetSmokeFanPower);
	sCmd.addCommand("!TARE", TareAllPSensors);
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

