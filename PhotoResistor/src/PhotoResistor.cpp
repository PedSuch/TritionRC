/*
    PhotoResistor.cpp - Library for PhotoResistor sensor
    Created by Pedro Suchite November 10, 2018
*/

#include "Arduino.h"     //standard arduino library
#include "PhotoResistor.h"
#define LIGHT_INTENSITY_THRESH 100

PhotoResistor::PhotoResistor( int sensorPin )
{
    _sensorPin = sensorPin;  //Stores pin value
    
    pinMode(LED_BUILTIN, OUTPUT);  //initilize led
    
    int sensorValue = 0;   //stores sensor value
    _Bool bright = false;  //stores if it is bright or not
}

void PhotoResistor::getLightIntensity()
{
    sensorValue = analogRead(_sensorPin);

    if( sensorValue > LIGHT_INTENSITY_THRESH )
    {
        bright = false;
        digitalWrite(LED_BUILTIN, LOW);
        delay(sensorValue);
        
    }
    else if ( sensorValue < LIGHT_INTENSITY_THRESH )
    {
        bright = true;
        digitalWrite(LED_BUILTIN, HIGH);
        delay(sensorValue);
    }
    Serial.println(bright);
}
