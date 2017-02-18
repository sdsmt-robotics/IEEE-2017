#ifndef PING_H
#define PING_H

#define STV 25.0  // Arbitrary Starting Value

#include "Sensors.h"

class Ping : Sensor{
public:
    Ping(std::string Name);

    // Getters
    double getValue(){ return value; };

    // Setters

    // Actions
    //void UpdateValues(double v);
    void UpdateSensors();

private:
    void InterpretValue();
    double value = 0.0;
    double values[10];

};

#endif