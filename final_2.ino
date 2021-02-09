#include <SoftwareSerial.h> // Include bluetooth library
SoftwareSerial BTSerial(10,11);
//The jumpers are connected to 10 and 11 -> RX / TX
//because the response from the module will be printed on the Serial Monitor

void setup(){
  Serial.begin(9600);
  Serial.print("Emergency mode activated");
  delay(1000)
  Serial.print("Found at (142, 172)");
  delay(500)
  Serial.print("Found at (203, 100)");
}

void loop(){
}
