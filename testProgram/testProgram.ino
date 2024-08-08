#include <Arduino.h>
#include <IRremote.h>


#define IR_RECEIVE_PIN 11



IRrecv irrecv(IR_RECEIVE_PIN);

decode_results results;

void setup() {


  Serial.begin(9600);

  irrecv.enableIRIn();   //start the receiver
}

void loop() {
  if(irrecv.decode(&results)) {
    
   //Serial.println(results.value);
   Serial.println(results.value,HEX);
   }
   irrecv.resume();
}

