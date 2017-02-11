#ifndef OBSTACLE_H
#define OBSTACLE_H

#define STV 25.0  // Arbitrary Starting Value

#include "Sensors.h"

class Obstacle : Sensor{
public:
    Obstacle(std::string Name);

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