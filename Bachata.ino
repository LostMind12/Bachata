#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Servo.h>
Servo SerAr;
Servo SerAb;
int TAC = 2;
static const uint8_t PROGMEM
  Normal[]= 
  {B00111100,
   B01111110,
   B11111111,
   B11100111,
   B11100111,
   B11111111,
   B01111110,
   B00111100},

  NormalIzq1[]=
  {B00111100,
B01111110,
B11111111,
B11111111,
B11100111,
B11100111,
B01111110,
B00111100},

NormalIzq2[]=
  {B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11100111,
B01100110,
B00111100},
NormalIzq3[]=
  {B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11111111,
B01100110,
B00100100},

NormalIzqAr1[]=
{B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B11111111,
B01001110,
B00001100},
NormalIzqAr2[]=
{B00111100,
B01111110,
B11111111,
B11111111,
B11111111,
B10011111,
B00011110,
B00111100},
NormalIzqAr3[]=
{B00111100,
B01111110,
B11111111,
B11111111,
B00111111,
B00111111,
B01111110,
B00111100},
NormalAr1[]=
{B00111100,
B01111110,
B11111111,
B11001111,
B11001111,
B11111111,
B01111110,
B00111100},
NormalAr2[]=
{B00111100,
B01111110,
B11111111,
B10011111,
B10011111,
B11111111,
B01111110,
B00111100},
NormalDer1[]=
{B00111100,
B01111110,
B11100111,
B11100111,
B11111111,
B11111111,
B01111110,
B00111100},
NormalDer2[]=
{B00111100,
B01100110,
B11100111,
B11111111,
B11111111,
B11111111,
B01111110,
B00111100},
NormalDerAr1[]=
{B00111100,
B01111110,
B10011111,
B10011111,
B11111111,
B11111111,
B01111110,
B00111100},
NormalDerAr2[]=
{B00111100,
B01001110,
B11001111,
B11111111,
B11111111,
B11111111,
B01111110,
B00111100};
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();


void setup() {
  pinMode (TAC, INPUT);
  SerAr.attach(4, 800, 2400);
  SerAb.attach(5, 650, 2400);
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}


  

void loop() {
 int activo = digitalRead(TAC);


 if(activo==HIGH){
  
 
 matrix.clear();
  matrix.drawBitmap(0, 0, Normal, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzq1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzq2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzq3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  SerAb.write(-90);}
   pausa();
   if(activo==HIGH){
matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzqAr1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzqAr2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();
  matrix.drawBitmap(0, 0, NormalIzqAr3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
 SerAr.write(-20);
 delay(100);
 pausa();
   if(activo==HIGH){
 SerAr.write(40);
 delay(100);}
   }
 }
  
 void pausa(){
  delay(50);
 while(digitalRead(TAC)==LOW){
delay(50);
 }
 }


