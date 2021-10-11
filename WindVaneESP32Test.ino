/*
 * @author: Avi Peltz
 * In this sketch we read from the Ardent Data Systems Wind Vane, Also sold under
 * the Sparkfun brand. It is a Wind Vane that uses Reed switches (basically switches 
 * triggered by a magnet) to idenify which direction the vane is pointed in. There are resistors
 * of different values in each directio you can look at the spec for the Wind Vane to find rough
 * resistor values, but I would recomend measuring the resistance and output voltage from your 
 * specific sensor as there is some variance.
 * 
 * When the magnet on the spinning portion of the vane is at a given direction the reed switch, 
 * switches and the circuit goes from open to closed through that specific resistor.
 * 
 * This was written for an ESP32, which has a 12-bit Resolution for its ADC pins, 
 * meaning the input voltage values read will be between 0-2^12 == 0-4095. An arduino
 * only has a 10 bit resultion for its ADC pins therefore the Vin constants would have to
 * be adjusted between 0-1023.
 * 
 */
#include <Wire.h>

#define VANE_PIN 39
int windDir;
unsigned int Vin;
float DirOut;

void getDirection()
{
    Vin = analogRead(VANE_PIN);
    Serial.print(Vin);
    
    if( Vin > 3430) windDir = 12;     //W   | 270º
    else if(Vin > 3180) windDir = 14; //NW  | 315º
    else if(Vin > 2910) windDir = 13; //WNW | 292.5º
    else if(Vin > 2750) windDir = 0;  //N   | 0º
    else if(Vin > 2440) windDir = 15; //NNW | 337.5º
    else if(Vin > 2170) windDir = 10; //SW  | 225º
    else if(Vin > 2070) windDir = 11; //WSW | 247.5º
    else if(Vin > 1570) windDir = 2;  //NE  | 45º
    else if(Vin > 1360) windDir = 1;  //NNE | 22.5º
    else if(Vin > 910) windDir = 8;   //S   | 180º
    else if(Vin > 740) windDir = 9;   //SSW | 202.5º
    else if(Vin > 520) windDir = 6;   //SE  | 135º
    else if(Vin > 300) windDir = 7;   //SSE | 157.5º
    else if(Vin > 180)  windDir = 4;  //E   | 90º
    else if(Vin > 140)  windDir = 3;  //ENE | 67.5º
    else windDir = 5;                 //ESE | 112.5º
  
}
void formatWindDir(){
  float constantVal = 22.5;
  DirOut = windDir * constantVal;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  getDirection(); // Stores new direction windDir
  formatWindDir();
  Serial.println(DirOut);
  delay(1000);
}
