#ifndef PING_H
#define PING_H

#define StartV 25.0     // Arbitrary Starting Value
#define DETECTED 10.0   // Arbitrary value to determine obstacle detection

#include "Sensors.h"

class Ping : Sensor{
public:
    Ping(std::string Name);

    // Getters
    double getValue(){ return value; };
    bool getDetected(){return detected; };

    // Setters

    // Actions
    //void UpdateValues(double v);
    void UpdateSensors();

private:
    double value = 0.0;
    double values[10];
    int walker = 0;
    bool detected = false;

    // Private Functions
    void InterpretValue();

};

#endif