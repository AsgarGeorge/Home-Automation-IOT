#include <IRremote.h>


#define IR_RECEIVE_PIN 11

int fan = 9;  //purple

int light1 = 10; //green
int light2 = 8;  //blue

int bulb = 12; //yelllow


int componentState[] = { 0, 0, 0, 0 };
int appliances[] = {9,10,8,12};

//Arrray is used to maintain the state of the appliances
//If the state is 0 the the component is "OFF",if the state is 1 the component is "ON"



// declaring the hexaDecimal code for each buttons
#define power  0xF708FB04

#define fanButton 0xBB44FB04

#define lightButton1 0xEE11FB04
#define lightButton2 0xED12FB04
#define lightButton3 0xEC13FB04

#define bulbButton 0xF00FFB04



//Counter Variable 

int lightCounter = 0;




void setup() {


 // Serial.begin(9600);

IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  //start the receiver

  pinMode(light1, OUTPUT);    // setup for the pin configuration
  pinMode(light2,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(bulb,OUTPUT);

  digitalWrite(fan,HIGH);
  digitalWrite(light1,HIGH);
  digitalWrite(light2,HIGH);
   digitalWrite(bulb,HIGH);

}

void loop() {
  if (IrReceiver.decode()) {
   unsigned long value = IrReceiver.decodedIRData.decodedRawData;  // checking for hexaCode
   //Serial.println(value,HEX);
  if(value != 0){
switch (value) {
  case fanButton:
    if(componentState[0]==0){
      digitalWrite(fan,LOW);
      componentState[0]=1;
    }else{
      digitalWrite(fan,HIGH);
      componentState[0]=0;
    }
    break;
  case lightButton1:
    if(componentState[1]==0){
      digitalWrite(light1,LOW);
      componentState[1]=1;
    }else{
      digitalWrite(light1,HIGH);
      componentState[1]=0;
    }break;

    case lightButton2:
    if(componentState[2]==0){
      digitalWrite(light2,LOW);
      componentState[2]=1;
    }else{
      digitalWrite(light2,HIGH);
      componentState[2]=0;
    }break;

    case lightButton3:
    if(lightCounter==0){
      for(int i = 1; i<3;i++){
      if(componentState[i]==0){
        digitalWrite(appliances[i],LOW);
        componentState[i]=1;
      }}
      lightCounter=1;
    }else{
      for(int i = 1; i<3;i++){
      if(componentState[i]==1){
        digitalWrite(appliances[i],HIGH);
        componentState[i]=0;
      }}
      lightCounter=0;
    }
    
    break;
    case bulbButton:
    if(componentState[3]==0){
      digitalWrite(bulb,LOW);
      componentState[3]=1;
    }else{
      digitalWrite(bulb,HIGH);
      componentState[3]=0;
    }
    break;
    case power:
    int localCounter=0;
    for(int i = 0; i<4 ; i++){
      
      if(componentState[i]==1){
        localCounter++;
      }
    }
    if(localCounter >= 1){
      for(int i = 0; i<4 ; i++){
        if(componentState[i]==1){
          digitalWrite(appliances[i],HIGH);
          componentState[i]=0;
          
      }}
    }else {
      for(int i = 0; i<4 ; i++){
        if(componentState[i]==0){
         digitalWrite(appliances[i],LOW);
         componentState[i]=1;
         
    }}
    }
    
    break;
    



  }
//   for(int i= 0;i<4;i++){
// Serial.print(componentState[i]," ");
// }Serial.println();

  
  
  }
  IrReceiver.resume();}
}

