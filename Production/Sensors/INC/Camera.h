#ifndef CAMERA_H
#define CAMERA_H

#include "Sensors.h"

class Camera : Sensor{
public:
    Camera(std::string Name);
    ~Camera();
    
    // Getters
    int getValue(){ return value; };

    // Setters

    // Actions    
    void UpdateSensors();

private:
    int value = 0;
    bool countedPips = false;

    // Private Functions
    int ReadCamera();
};

#endif