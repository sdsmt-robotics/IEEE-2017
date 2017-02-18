#ifndef SAMPLESENSOR_H
#define SAMPLESENSOR_H

#include "Sensors.h"

class SampleSensor : Sensor{
public:
    // ENSURE this is called in SensorHandler's constructor and that a pointer
    // to it is made in the private section of SensorHandler. 
    SampleSensor(std::string Name);  

    // Getters
    // int getValue(){ return value; };

    // Setters
    // void setValue(int v){ value = v; };

    // Actions
    void UpdateSensors();   // Inherited, must be here


private:
    int value = 0;

    // Private Functions
    void InterpretValue();
};


#endif