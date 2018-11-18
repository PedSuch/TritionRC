/*
 PhotoResistor.h - Library for using Photoresistor light
 sensor
 Created by Pedro Suchite, November 10, 2018
*/

#ifndef    PhotoResistor_h
#define    PhotoResistor_h

#if ARDUINO  >= 100
    #include "Arduino.h"
#else
    #include "WPrograms.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

class PhotoResistor {
    public:
        PhotoResistor( int sensorPin );
        void getLightIntensity();
    private:
        int _sensorPin;
        int sensorValue;
        _Bool bright;
};

#endif
