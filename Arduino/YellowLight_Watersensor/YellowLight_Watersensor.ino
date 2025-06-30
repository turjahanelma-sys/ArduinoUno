//Arduino water level sensor code
// Sensor pins pin D6 LED output, pin A0 analog Input
#define sensorPin A0
#define lowOutput  2
#define mediumOutput  3
#define highOutput  4
void setup() {
  Serial.begin(9600);
  pinMode(lowOutput , OUTPUT);
  pinMode(mediumOutput , OUTPUT);
  pinMode(highOutput , OUTPUT);
  digitalWrite(lowOutput, LOW);
  digitalWrite(mediumOutput, LOW);
  digitalWrite(highOutput, LOW);
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  if (280 > sensorValue) {
    digitalWrite(lowOutput, HIGH);
    digitalWrite(highOutput, LOW);
    digitalWrite(mediumOutput, LOW);
  }  else if (564 > sensorValue) {
    digitalWrite(mediumOutput, HIGH);
    digitalWrite(highOutput, LOW);
    digitalWrite(lowOutput, LOW);
  } else if (640 > sensorValue) {
    digitalWrite(highOutput, HIGH);
    digitalWrite(mediumOutput, LOW);
    digitalWrite(lowOutput, LOW);
  } else {
    digitalWrite(highOutput, LOW);
    digitalWrite(mediumOutput, LOW);
    digitalWrite(lowOutput, LOW);
  }
  delay(100);
}