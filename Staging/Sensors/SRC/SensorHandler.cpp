#include "SensorHandler.h"

SensorHandler::SensorHandler(Arduino *A)
{
    cam = new Camera("Camera") : Sensor(*A);
    mouse = new Mouse("Mouse") : Sensor(*A);
    tunnel = new TunnelDetection("Tunnel Detector") : Sensor(*A);
    for (unsigned int i = 0; i < 4; ++i)
        ping[i] = new Obstacle("Obstacle Detector") : Sensor(*A);
}

SensorHandler::~SensorHandler()
{
    delete cam;
    delete mouse;
    delete tunnel;
    for (unsigned int i = 0; i < 4; ++i)
        delete ping[i];
}

void SensorHandler::UpdateAllSensors()
{
    cam->UpdateSensors();
    mouse->UpdateSensors();
    tunnel->UpdateSensors();
    for (unsigned int i = 0; i < 4; ++i)
        ping[i]->UpdateSensors();
}