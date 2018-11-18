#include <PhotoResistor.h>
#include <UltraSonic.h>

#include <Arduino.h>
/*
 * PingWithLibraryV1.
 * 
 * Displays to the serial monitor the distance of an object
 * within the specified range. Imports Sensors Library
 * 
 * Created November 3rd, 2018
 * Pedro Suchite
 */
 //pins to use for UltraSonic sensor
 #define echoPin A0
 #define trigPin A1 
 #define sensorPin A2

 unsigned long previousMillisUltraS = 0;
 long onTimeUltraS = 250;
 long offTimeUltraS = 750;
 
 unsigned long previousMillisPhotoR = 0;
 long onTimePhotoR = 250;
 long offTimePhotoR = 750;

 UltraSonic sensors(echoPin, trigPin);
 PhotoResistor resistor(sensorPin);

 void setup() {
  Serial.begin(9600);
  }

void loop() {
  unsigned long currentMillis = millis();
  
  if( (currentMillis - previousMillisUltraS >= onTimeUltraS) ) 
  {
    previousMillisUltraS = currentMillis;
    sensors.getDistance(); //gets distance and prints it 
  }
  else if( currentMillis = previousMillisPhotoR >= offTimePhotoR ) 
  {
    previousMillisPhotoR = currentMillis;
    
    //prints boolean value whether it is bright or not
    resistor.getLightIntensity(); 
  }
    
}
