#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_system.h"


#define Watchdog 7
#define LED 12
#define BUTTON 3
#define ANALOGUE 14


void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );
void Task4and5( void *pvParameters );
void Task6( void *pvParameters );
void Task7and8( void *pvParameters );
void Task9( void *pvParameters );

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

   xTaskCreate(
    Task1
    ,  "task1"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task2
    ,  "task2"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task3
    ,  "task3"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task4and5
    ,  "task4and5"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task6
    ,  "task6"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task7and8
    ,  "task7and8"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
    xTaskCreate(
    Task9
    ,  "task9"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );

}

void loop() {
  // put your main code here, to run repeatedly:

}


void Task1(void *pvParameters ){
   digitalWrite(Watchdog,HIGH);//Send HIGH signal, turn LED on
   vTaskDelay( 300 / portTICK_PERIOD_MS ); 
   digitalWrite(Watchdog,LOW);//Send LOW signal, turn LED off
}

void Task2(void *pvParameters ){
  BUTTONstate = digitalRead(BUTTON); //Read button
}

void Task3(void *pvParameters ){
  while (digitalRead(1)== HIGH){
    //Start timer 
  }
  //Stop timer
  //Timer multiplied by frequency
  
}

void Task4and5(void *pvParameters ){
  //Get analogue reading 4 times
  int analogue1 = analogRead(ANALOGUE);
  int analogue2 = analogRead(ANALOGUE);
  int analogue3 = analogRead(ANALOGUE);
  int analogue4 = analogRead(ANALOGUE);

  average_analogue = (analogue1+analogue2+analogue3+analogue4)/4;//Get average analogue
}




void Task6(void *pvParameters ){
  int i = 0;
  while( i >1000){//Do 1000 times
    __asm__ __volatile__ ("nop");
    i++;
  }
}

void Task7and8(void *pvParameters ){
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

void Task9(void *pvParameters ){
  //CSV
  //Semaphores to wait for values
  Serial.print(BUTTONstate);
  Serial.print(",");
  Serial.print(average_analogue);
  Serial.print(",");
  Serial.print(Frequency);
    
}
