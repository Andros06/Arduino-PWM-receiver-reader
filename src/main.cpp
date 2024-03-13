
#include <Arduino.h>

int ch1; // Here's where we'll keep our channel values
int ch2;
int ch3;

int mappedch1;
int mappedch2;
int mappedch3;

void setup() {
  pinMode(3, INPUT); // Set our input pins as such
  pinMode(5, INPUT);
  pinMode(6, INPUT);

  Serial.begin(9600);
}

void loop() {
  ch1 = pulseIn(3, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(5, HIGH, 25000); // each channel
  ch3 = pulseIn(6, HIGH, 25000);

  mappedch2 = constrain(map(ch2, 2015, 1075, -100, 100), -100, 100);
  mappedch3 = constrain(map(ch3, 1469, 1575, -100, 100), -100, 100);

  if(ch1 > 1800){
    mappedch1 = 1;
  }
  else{
    mappedch1 = 0;
  }

  if( mappedch2 < 5 && mappedch2 > -5){
    mappedch2 = 0;
  }

  if( mappedch3 < 1525 && mappedch3 > 1515){
    mappedch3 = 0;
  }

  //Serial.println(mappedch1);
  //Serial.println(mappedch2);
  //Serial.println(mappedch3);
  

  delay(100); 
}