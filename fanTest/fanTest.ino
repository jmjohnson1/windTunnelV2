uint8_t fanPin = 3;
uint8_t potPin = 14;

int fanPower = 0;

void setup() {
	Serial.begin(500000);
	pinMode(fanPin, OUTPUT);
	pinMode(potPin, INPUT);
	analogWriteFrequency(fanPin, 24000);
}

void loop() {
	int potValue = analogRead(potPin);
	fanPower = map(potValue, 0, 1023, 0, 255);
  Serial.print("pot: ");
  Serial.print(potValue);
  Serial.print(" pow: ");
  Serial.println(fanPower);
	analogWrite(fanPin, fanPower);
  delay(1000);
}
