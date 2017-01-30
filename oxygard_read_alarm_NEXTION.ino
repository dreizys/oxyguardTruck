#include <Nextion.h>

/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

int count_con = 7;
#include <Nextion.h>
#define nextion Serial
Nextion myNextion(nextion, 9600);
   

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A5, INPUT);   // addoing analog pin A5 as digital 14

  // myNextion.init("page0");
  // String message = myNextion.listen();
 //  if (message = ""
  
   myNextion.init("page1");//Nextion page number
 
    for (int i = 2; i <= 11; i++) {//using pin2-pin12
       pinMode(i, OUTPUT);
       digitalWrite(i,HIGH);
    }
}

// the loop routine runs over and over again forever:
void loop() {
 
  
  for (int i = 1; i <= count_con; i++) {
 
    
    digitalWrite(i+1, LOW); //relay on starting  from pin2
      String NextionElementID = "t0";
    myNextion.setComponentText(NextionElementID, String(i));
    
    myNextion.sendCommand("t0.bco=65535");//set white colour for text field background
    
    delay(12000);
        if (digitalRead(A5)==HIGH) {
    myNextion.sendCommand("t0.bco=63488");//red colour for text field background
    
    } 
    else {
      myNextion.sendCommand("t0.bco=2024"); //green colour for text field background
    }
    
   //Serial.print(i);
  
  
    
    //NextionElementID += String(i-1);
    //Serial.print(NextionElementID);
    
   
   // myNextion.setComponentBgcolor(
    
    delay(5000);

    digitalWrite(i+1, HIGH); //relay off
     if (Serial.available() > 0) {
    char incoming = Serial.parseInt();
    
    count_con = incoming;
    break;
    } 
    //if (i == count_con) i = 1; // оказалось, что и без нее все работает
  }
  
  
}
