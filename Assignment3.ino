#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#define Watchdog 7
#define LED 12
#define BUTTON 3
#define ANALOGUE 14

int average_analogue = 0;
int BUTTONstate = 0;
int Frequency = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Watchdog, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
  pinMode(ANALOGUE,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}


void Task1(){
   digitalWrite(Watchdog,HIGH);//Send HIGH signal, turn LED on
   delayMicroseconds(50);
   digitalWrite(Watchdog,LOW);//Send LOW signal, turn LED off
}

void Task2(){
  BUTTONstate = digitalRead(BUTTON); //Read button
}

void Task3(){
  
}

void Task4and5(){
  //Get analogue reading 4 times
  int analogue1 = analogRead(ANALOGUE);
  int analogue2 = analogRead(ANALOGUE);
  int analogue3 = analogRead(ANALOGUE);
  int analogue4 = analogRead(ANALOGUE);

  average_analogue = (analogue1+analogue2+analogue3+analogue4)/4;//Get average analogue
}




void Task6(){
  int i = 0;
  while( i >1000){//Do 1000 times
    __asm__ __volatile__ ("nop");
    i++;
  }
}

void Task7and8(){
  int error_code;
  if (average_analogue > 3300/2){
    error_code = 1;
    digitalWrite(LED,HIGH);//Send HIGH signal, turn LED on
  }
else{
    error_code = 0;
    digitalWrite(LED,LOW);//Send LOW signal, turn LED off

  
}
}

void Task9(){
  //CSV
  Serial.print(BUTTONstate);
  Serial.print(",");
  Serial.print(average_analogue);
  Serial.print(",");
  Serial.print(Frequency);
    
}
