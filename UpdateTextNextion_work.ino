/*

Ricardo Mena C
ricardo@crcibernetica.com
http://crcibernetica.com

  This example code is in public domain

*/

#include <SoftwareSerial.h>
#include <Nextion.h>
#define nextion Serial

//SoftwareSerial nextion(0, 1);// Nextion TX to pin 2 and RX to pin 3 of Arduino

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

void setup() {
  Serial.begin(9600);
  myNextion.init("page1");

}

void loop() {
 
   delay(3000);
   myNextion.setComponentText("t10", "8"); 
   delay(3000);
   myNextion.setComponentText("t11", "10");// update text using original sensor valu
 // myNextion.sendCommand("ref n0");
  
}

