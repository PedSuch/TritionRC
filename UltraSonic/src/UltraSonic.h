/*
   UltraSonic.h - Library for using Ultrasonic
   Sensor
   Created by Pedro Suchite, November 3 2018
*/
#ifndef  UltraSonic_h
#define UltraSonic_h

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

class UltraSonic {
    public:
        UltraSonic(int echoPin,int trigPin);
        void getDistance();
    private:
        int _trigPin;
        int _echoPin;
        unsigned long HR_dist;
        unsigned long duration;
};

#endif
