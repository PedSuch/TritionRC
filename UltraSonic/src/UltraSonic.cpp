/*
  UltraSonic.cpp - Library for ultrasonic sensor.
  Created by Pedro Suchite November 3, 2018
*/

#include "Arduino.h"     //standard arduino library
#include "UltraSonic.h"  //this library's header
#define MIN_RANGE 5      //minimum desired range of Sensor
#define MAX_RANGE 200    //max desired range of Sensor
#define CM_CONVERSION 58.2  //value to convert time to CM

UltraSonic::UltraSonic(int echoPin, int trigPin)
{
    _echoPin = echoPin;
    _trigPin = trigPin;
    
    /* Sets our pins to respective output and input */
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    
    /*Initialize our variables for duration and distance detected*/
    duration = 0;
    HR_dist = 0;
}

void UltraSonic::getDistance()
{

    digitalWrite(_trigPin,LOW);
    delayMicroseconds(2);

    digitalWrite(_trigPin,HIGH);
    delayMicroseconds(10);
    
    digitalWrite(_trigPin,LOW);
   
    duration = pulseIn(_echoPin,HIGH);  //returns duration of pulse
    
    HR_dist = duration/CM_CONVERSION;  //converts to CM
 
    if (HR_dist>= MAX_RANGE || HR_dist <= MIN_RANGE){
      Serial.println("0");  //outside of desired range: print 0
        
    } else {
      Serial.println(HR_dist);  //otherwise print distance
     
    }
}
