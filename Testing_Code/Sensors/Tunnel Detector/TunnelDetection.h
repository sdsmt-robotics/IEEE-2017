#ifndef TUNNELDETECTION_H
#define TUNNELDETECTION_H

#include "Sensors.h"

class TunnelDetection : Sensor{
public:
    TunnelDetection(std::string Name);

    // Getters
    int getValue(){ return value; };

    // Setters
    void setValue(int v){ value = v; };

    // Actions
    void UpdateSensors();

private:
    int value = 0;

};

#endif