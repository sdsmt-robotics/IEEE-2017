#ifndef TUNNELDETECTOR_H
#define TUNNELDETECTOR_H

#include "Sensors.h"

class TunnelDetector : Sensor{
public:
    TunnelDetector(std::string Name);

    // Getters
    bool getValue(){ return value; };

    // Setters
    void setValue(int v){ value = v; };

    // Actions
    void UpdateSensors();

private:
    bool value = 0;

    // Private Functions
    void InterpretValue();
};

#endif