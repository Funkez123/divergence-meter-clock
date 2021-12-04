#include "SevSeg.h"
#include <DS3231.h>
#include <Wire.h>


SevSeg Display;

DS3231 clock;
bool century = false;
bool h12Flag;
bool pmFlag;
byte alarmDay, alarmHour, alarmMinute, alarmSecond, alarmBits;
bool alarmDy, alarmH12Flag, alarmPmFlag;
float zufall;

const unsigned long period = 1000; //one second
const unsigned long led_period = 500; //LED blink millisecond
unsigned long startMillis;
unsigned long led_startMillis;
unsigned long currentMillis;
unsigned long led_currentMillis;
const int hrs_btn = A0;
const int min_btn = A1;
const int ledPin = A2;
long Hrs = 12;
long Min = 0;
long Sec = 0; 
long Time = 0;
int ledState = LOW;

int mil = 0;

void setup() {

 pinMode(6,OUTPUT);
 pinMode(9,OUTPUT);

    Wire.begin();
    
  byte numDigits = 8;
  byte digitPins[] = {28, 32, 35, 34,10,11,12,13};
  byte segmentPins[] = {2, 3, 4, 19, 7, 18, 9, 5}; // pls change to prefered wiring
  bool resistorsOnSegments = true; // pins
  byte hardwareConfig = COMMON_CATHODE; //
  bool updateWithDelays = true; //
  bool leadingZeros = true; //
  Display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  Display.setBrightness(20); // Brightness can be configured

  Serial.begin(9600);
}

void loop() {

  
  static unsigned long timer = millis();
  static int deciSeconds = 0;

 if (millis() - timer >= 1) {
    timer += 10;
    analogWrite(A0, 170);

    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
 }
    if (deciSeconds == 99) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
      analogWrite(A0, 0);

    }
  
Hrs = clock.getHour(h12Flag, pmFlag);
Min = clock.getMinute();
Sec = clock.getSecond();
mil = deciSeconds;

if (Hrs == 0 && Min == 0) {
  zufall = random(1,100);
if (zufall > 50) {
  
  digitalWrite(6,HIGH);
  digitalWrite(8,LOW);
  
  }
  else
  {
    digitalWrite(8,HIGH);
  digitalWrite(6,LOW);
    }
  }

 Time = ((Hrs*1000000) + (Min*10000) + (Sec*100) + (mil)) ;
  Display.setNumber(Time,6);
  Display.refreshDisplay();
}
