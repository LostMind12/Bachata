
#include <Servo.h>
#include <Adafruit_LEDBackpack.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Servo servoar;
Servo servoab;
int TAC = 2;
int Zumbador = 7;
int activo = digitalRead(TAC);
int pul1 = 9;
int pul2 = 10;

static const uint8_t PROGMEM
 primer[][8]={  
  
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
   B00100100},

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
{B10011100,
B01011110,
B01011111,
B00011111,
B00011111,
B01011111,
B01011110,
B10011100};
   Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
void setup() {
  servoar.attach(5);
  servoab.attach(4);
 pinMode (TAC, INPUT);
  pinMode (Zumbador, OUTPUT);
  Serial.begin(9600);
 matrix.begin(0x70);
}

void mov() {
  for (int i=0; i<8; i++){
    pausa();
    easteregg();
    matrix.clear();
    matrix.drawBitmap(0, 0, primer[i], 8, 8, LED_ON);
    matrix.writeDisplay();

    if (i==1){  
      servoar.write(90);
      servoab.write(90);
      
    }
    if (i==5){  
      servoab.write(60);
    }
    if (i==7){
      servoar.write(60);
    }
    delay(200);  
  }
}


void pausa(){
  
while(digitalRead(TAC)==HIGH){
  
  matrix.clear();
  matrix.drawBitmap(0, 0, Emfadao, 8, 8, LED_ON);
  matrix.writeDisplay();
  tone(Zumbador, 50, 100);
  
  servoar.write(90);
  servoab.write(100);
  delay(50);
  servoab.write(90);
  delay(50);
  
  
}
}
void easteregg(){
  int  puls1=digitalRead(pul1);
int  puls2=digitalRead(pul2);
if (puls1 == HIGH){
  tone(Zumbador, 1000, 100);
  delay(10);
}
if (puls2 == HIGH){
  tone(Zumbador, 1500, 100);
  delay(10);
}
}
void loop() {
easteregg();

mov();

}
  

  



