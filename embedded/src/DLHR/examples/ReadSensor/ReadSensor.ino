#include <Wire.h>

#include <AllSensors_DLHR.h>

AllSensors_DLHR_L02D_8 gagePressure(&Wire);

void setup() {
  Serial.begin(115200);

  Wire.begin();
  Wire.setClock(200000);

  gagePressure.setPressureUnit(AllSensors_DLHR::PressureUnit::PASCAL);
}

void loop() {
  gagePressure.readStatus();
  gagePressure.startMeasurement();
  gagePressure.readData(true);
  Serial.print("Pressure: ");
  Serial.print(gagePressure.pressure);
  Serial.print(" Temperature: ");
  Serial.println(gagePressure.temperature);
  Serial.print(" Status: ");
  Serial.println(gagePressure.status);

  delay(100);
}
