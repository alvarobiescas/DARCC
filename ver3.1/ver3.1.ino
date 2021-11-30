/*
 * 
 * mide una vuelta 23.6
 * bluetooth
 * 
 */


#include "BluetoothSerial.h" 
BluetoothSerial ESP_BT; 

const int channel_a = 12;
const int channel_b = 14;
volatile unsigned long count_core = 1;              
double consig = 23.6;
int constante = 3900;                                           // 600+600*3.25, channelA+channelB*(65/20), 65/20 ruedas 
double master = 0;


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
  master =double ((count_core)*(consig))/(constante);
  Serial.println (count_core);
  Serial.println (master);
  
  ESP_BT.print(count_core);
  
  delay(100);    
}




  

  
