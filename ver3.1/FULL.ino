/*
#include <Wire.h>
#include <SoftwareSerial.h>                                       // libreria que permite establecer pines digitales

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128                                        // OLED display width, in pixels
#define SCREEN_HEIGHT 64                                        // OLED display height, in pixels
#define OLED_RESET -1                                           // Reset pin # (or -1 if sharing reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial BT_COUNT(10, 11);                                // pin 10 como RX, pin 11 como TX


const int channel_a = 2;
const int channel_b = 3;

int constante = 3900;                                           // 600+600*3.25, channelA+channelB*(65/20), 65/20 ruedas 
int k1;
int k2;
int pulsos = 0;
int focus = 0;

volatile unsigned long count_core = 1;                        //This variable will increase or decrease depending on the rotation of encoder
unsigned long count_temp = 1;                                 //This variable will increase or decrease depending on the rotation of encoder
int time_1=0;

double master = 0;

float Dato1 = 0;                            
float Dato2 = 0;

char val;

String palabra;
String linea_1;
String linea_2;




    
void setup() 
{
  Serial.begin (9600);
  BT_COUNT.begin(9600);                                       // comunicacion serie entre Arduino y el modulo a 9600 bps

  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;                                                       // Don't proceed, loop forever
  }

  display.display();
  delay(2);
  display.clearDisplay();

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(3);
  display.setCursor(5, 5);
  display.print("DARCC");
  display.setCursor(30, 35);
  display.print("RFEA");
  display.display();
  delay(1000);


  pinMode(channel_a, INPUT_PULLUP); 
  pinMode(channel_b, INPUT_PULLUP);               

  attachInterrupt(digitalPinToInterrupt(channel_a), int_0, RISING);                  
  attachInterrupt(digitalPinToInterrupt(channel_b), int_1, RISING);   
  attachInterrupt(digitalPinToInterrupt(pulsador12), pulsado, RISING);


  focus=0; 
  time_1=millis()+10000;              
  }


void loop() 
  {
 
  if (focus==0)
      {
       display.clearDisplay();
       display.setTextColor(WHITE);
       display.setTextSize(2);
       display.setCursor(5, 5);
       display.print("CONFIG");
       display.setCursor(5, 35);
       display.print(time_1 - millis());
       display.display();
  
       if(BT_COUNT.available())
          {
            val = BT_COUNT.read();  
            palabra = palabra + val; 

            if (val == '$') 
                {
                k1 = palabra.indexOf(',');
                linea_1 = palabra.substring(0, k1);
                k2 = palabra.indexOf(',', k1+1);
                linea_2 = palabra.substring(k1+1, k2);
                palabra = "";
/*
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(linea_1);
            lcd.setCursor(10,0);
            lcd.print(linea_2);
       
            Serial.print("linea_1  ------> ");  
            Serial.println(linea_1);
            Serial.print("linea_2  ------> ");
            Serial.println(linea_2);

                Dato1 = linea_2.toFloat();
                Dato2 = linea_1.toFloat();   
                }
        } 
      if (time_1 - millis() <= 0)
         {
          focus=1;
         }
    }

if (focus==1)
 {    
    if( count_core != count_temp )
      {
      master = double (count_core)/(pulsos);              // calculo como si count_core no es long sino double.
      count_temp = count_core;
      }
      Serial.print (count_core);
      Serial.print ("------");
      Serial.print (master);
      Serial.print ("------");
      Serial.print (pulsos);
      Serial.print ("------");
      Serial.print (Dato1);
      Serial.print ("------");
      Serial.print (Dato2);
      Serial.println ("-------------------------");

      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print("CORE");
      display.print(count_core);  
      display.setTextSize(2);
      display.setCursor(0, 25);
      display.print("MASTER");
      display.print(master);  
      display.display();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////  envio y recepcion bluetooth app     ////////////////////////////////////////////////////////////////////////    

      BT_COUNT.print(count_core);
      BT_COUNT.print("|");
      BT_COUNT.print(master);
      BT_COUNT.print("|");
      BT_COUNT.print(Dato1);
      BT_COUNT.print("|");
      BT_COUNT.print(Dato2);
      BT_COUNT.print("|");
      BT_COUNT.print(pulsos);
      BT_COUNT.print("\n");                         // Fin de línea. Importante.master appinventor


      pulsos=constante/Dato1;
      delay(100);    
    }
  }




   
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

  */
