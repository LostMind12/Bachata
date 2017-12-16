#include <Adafruit_LEDBackpack.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
int TAC = 2;
int Zumbador = 7;

static const uint8_t PROGMEM
 primer[][8]=
{  
  {B00111100,
   B01111110,
   B11111111,
   B11100111,
   B11100111,
   B11111111,
   B01111110,
   B00111100},
  
  {B00111100,
B01111110,
B11111111,
B11111111,
B11100111,
B11100111,
B01111110,
B00111100},

  {B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11100111,
B01100110,
B00111100},

{B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11111111,
B01100110,
B00100100}
};
static const uint8_t PROGMEM
segund[][8]={

{B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11001111,
B01001110,
B00111100},

{B00111100,
B01111110,
B11111111,
B11111111,
B10011111,
B10011111,
B01111110,
B00111100},

{B00111100,
B01111110,
B11111111,
B00111111,
B00111111,
B11111111,
B01111110,
B00111100}
};
static const uint8_t PROGMEM
Emfadao[]=
{B10000001,         // Fully open annoyed eye
 B01100110,
        B00000000,
        B11111111,
        B11111111,
        B11111111,
        B01111110,
        B00111100};
   Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
void setup() {
 pinMode (TAC, INPUT);
  pinMode (Zumbador, OUTPUT);
  
 matrix.begin(0x70);
}

void baile() {
  for (int i=0; i<4; i++){
   matrix.clear();
  matrix.drawBitmap(0, 0, primer[i], 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);
  pausa();
}

for (int i=0; i<3; i++){
   matrix.clear();
  matrix.drawBitmap(0, 0, segund[i], 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);
  pausa();
}

}
void pausa(){

while(digitalRead(TAC)==HIGH){
  tone(Zumbador, 100, 100);
  matrix.clear();
  matrix.drawBitmap(0, 0, Emfadao, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);
delay(50);
}
}
void loop() {
  int activo = digitalRead(TAC);
int Suena = digitalRead(Zumbador);
 if (activo==HIGH){
    
    delay(100);
    
  }
 
baile();
}
  

  



