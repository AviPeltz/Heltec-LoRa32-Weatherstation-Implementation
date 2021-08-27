
//MH-RD Raindrop Module pin definition
#define rainAnalog 37
#define rainDigital 38

void setup() {
  Serial.begin(9600);
  pinMode(rainDigital,INPUT);
}

void loop() {
  int rainAnalogVal = analogRead(rainAnalog);
  int rainDigitalVal = digitalRead(rainDigital);

  Serial.print(rainAnalogVal);
  Serial.print("\t");
  Serial.println(rainDigitalVal);
  delay(200);

}
