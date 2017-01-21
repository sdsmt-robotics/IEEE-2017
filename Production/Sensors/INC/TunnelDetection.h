#ifndef TUNNELDETECTION_H
#define TUNNELDETECTION_H

#include "Sensors.h"

class TunnelDetection : Sensor{
public:
    TunnelDetection(std::string Name);

    // Getters
    bool getValue(){ return value; };

    // Setters
    void setValue(int v){ value = v; };

    // Actions
    void UpdateSensors();

private:
    bool value = 0;

};

#endif