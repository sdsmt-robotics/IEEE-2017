#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include "Sensors.h"
#include "Camera.h"
#include "Mouse.h"
#include "TunnelDetection.h"
#include "Ping.h"

class SensorHandler{
public:
    SensorHandler(Arduino *A);
    ~SensorHandler();

    // Getters
    Camera* getCameraSensor(){ return cam; };
    Mouse* getMouseSensor(){ return mouse; };
    TunnelDetection* getTunnelSensor(){ return tunnel; };
    Ping* getObstacleSensor(){ return obstacle; };

    // Setters

    // Actions
    void UpdateAllSensors();

private:
    Camera *cam = nullptr;
    Mouse *mouse = nullptr;
    TunnelDetection *tunnel = nullptr;
    Ping **ping[4] = nullptr;
};

#endif