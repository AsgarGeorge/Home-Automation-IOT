#include <IRremote.h>


#define IR_RECEIVE_PIN 11


int light1 = 7;
int light2 = 13;
int fan = 9;
int bulb = 10;


int componentState[] = { 0, 0, 0, 0, 0 };


// declaring the hexaDecimal code for each buttons
#define fanButton 339227911
#define lightButton1 0x371A3C86
#define lightButton2 0x143226DB
#define bulbButton 0x80BF718E
#define button5 0x39D41DC6




void setup() {


  Serial.begin(9600);


  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  //start the receiver

  pinMode(light1, OUTPUT); // setup for the pin configuration
  pinMode(light2,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(bulb,OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
int value=IrReceiver.decodedIRData.decodedRawData;
if(value != 0){
  Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
   
  }
   IrReceiver.resume();
    
}
}