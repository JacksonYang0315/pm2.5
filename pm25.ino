int measurePin = 0;
int ledPower = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  digitalWrite(ledPower, LOW);
  delayMicroseconds(280);
  float voMeasured = analogRead(measurePin);
  delayMicroseconds(40);

  digitalWrite(ledPower, HIGH);
  delayMicroseconds(9680);

  float calcVoltage = voMeasured * (5.0 / 1024.0);
  float dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("PM 2.5 =");
  Serial.print(dustDensity * 1000);
  Serial.println("ug/m3");
  delay(1000);
}

