#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <SparkFunMLX90614.h> // Include IR thermometer library
#include <SoftwareSerial.h> // Include bluetooth library
/*
 * 2nd code: (infrared, bluetooth, LED, motor) The Emergency Protocol
 * When it activates,
 * It moves around again
 * Detects people—> send through bluetooth
 * 
 */

//calculate the amount of time that it takes to move towards a certain point
//send location? what is the location

IRTherm temp; 
SoftwareSerial BTSerial(10,11);
//The jumpers are connected to 10 and 11 -> RX / TX
//because the response from the module will be printed on the Serial Monitor

void setup(){
   // put your setup code here, to run once:
  temp.begin(); // Initialize I2C library and the MLX90614
  temp.setUnit(TEMP_F); // Set units to Farenheit (alternatively TEMP_C or TEMP_K)
  Serial.begin(9600);
  BTSerial.begin(38400);
  BTSerial.print("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!"); //check status
  const int motorPin = 4;
}

void loop(){
  // put your main code here, to run repeatedly:
  //motor is running forward, then turning
  analogWrite(motorPin1, 200); //either wheel
  analogWrite(motorPin2, 200);
  if (temp.read()) // Read from the sensor
  { // If the read is successful:
    float objectTemp = temp.object();
    Serial.println("Object: " + String(objectT));
    if(objectTemp == 86 || button == true){ //replace with actual human body temp
      analogWrite(motorPin1, 0);
      analogWrite(motorPin2, 0);
      //LED Flash a color to show recognition
      delay(1000);
      analogWrite (motorPin2, 100); //turn left/right
      delay(1000);
      //send location through bluetooth (but this isn't the actual location)
      if (Serial.available())
        BTSerial.write(Serial.read());
      }
  }
  delay(500);
}
