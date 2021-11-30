//#include <Wire.h>
#include "BluetoothSerial.h" 


// init Class:
BluetoothSerial ESP_BT; 

const int channel_a = 12;
const int channel_b = 14;

volatile unsigned long count_core = 1;                        //This variable will increase or decrease depending on the rotation of encoder
 
  void IRAM_ATTR int_0() 
  {
  if(digitalRead(channel_b)==LOW) {
  count_core++;
  }else{
  count_core--;
  }
  }

  void IRAM_ATTR int_1() 
  {
  if(digitalRead(channel_a)==LOW) {
  count_core--;
  }else{
  count_core++;
  }
  }


    
void setup() 
{
  Serial.begin (115200);
  
  ESP_BT.begin("COUNT_ESP"); //Name of your Bluetooth interface -> will show up on your phone
 
  pinMode(channel_a, INPUT_PULLUP); 
  pinMode(channel_b, INPUT_PULLUP);               

  attachInterrupt(digitalPinToInterrupt(channel_a), int_0, RISING);                  
  attachInterrupt(digitalPinToInterrupt(channel_b), int_1, RISING);   
         
}


void loop() 
{
      Serial.println (count_core);
      ESP_BT.print(count_core);
      delay(100);    
    
}




  

  
