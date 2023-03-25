/*
   Board Sparkfun Redboard

   2    D2    PD2   INT0
   3    D3    PD3   INT1

   8255
   Port A D0-7 <--> Arduino PC0-3,PD4-7 (A0-3, D4-7)

   8255 to Redboard
   PC7  /OBF   output to  Arduino pin 2 (INT0), falling edge
   PC6  /ACK   input from Arduino pin A5 (PC5)
   read data

   Redboard to 8255
   write data
   PC4  /STB   input from Arduino pin A4 (PC4)
   PC5  IBF    output to  Arduino pin 3 (INT1), falling edge

   SoftwareSerial
   Tx   9
   Rx   8

   microSD shield
   CS   8
   MOSI 11
   MISO 12
   SCK  13
*/

#include <SoftwareSerial.h>
#include "intf_8255.h"

const byte rxPin = 8;
const byte txPin = 9;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  // Define pin modes for TX and RX
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  // Set the baud rate for the SoftwareSerial object
  mySerial.begin(9600);
  mySerial.println("Hello world!");

  intf_8255_init();
  delay(500);
}

void loop() {
  byte value = 0;

  value = ReadFrom8255();
  mySerial.println(value, HEX);
  delay(100);

  //  if (mySerial.available() > 0) {
  //    WriteTo8255(mySerial.read());
  //  }

  //  do
  //  {
  //    WriteTo8255(value++);
  //    delay(100);
  //  } while(true);
}
