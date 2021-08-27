
/* Capacitive Soil Moisture Sensor v1.0 Setup Example
 *  
 * int dry : is the max value coming from the sensor when its 
 * fully dry in the air.
 * 
 * int wet : is the min value coming from the sensor when it is 
 * submerged in a cup of water within the reccommended depth
 * 
 * ^- These values are sensor dependent and should be measured for
 * each new sensor
 */
const int dry = 2940;   // replace with your tested dry value
const int wet = 1300;   // replace with your tested wet value
//int intervals = (AirValue - WaterValue)/3;
int sensorVal = 0;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop() 
{
  sensorVal = analogRead(36);  //connect sensor to ADC1_0, pin 36
  int humPerc = map(sensorVal, wet, dry, 100, 0);
  Serial.print(humPerc);
  Serial.println("%");
  delay(500);
}
