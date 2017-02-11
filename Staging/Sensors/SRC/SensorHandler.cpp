#include "SensorHandler.h"

SensorHandler::SensorHandler(Arduino *A)
{
    cam = new Camera("Camera") : Sensor(*A);
    mouse = new Mouse("Mouse") : Sensor(*A);;
    tunnel = new TunnelDetection("Tunnel Detector") : Sensor(*A);;
    obstacle = new Obstacle("Obstacle Detector") : Sensor(*A);;
}

SensorHandler::~SensorHandler()
{
    delete cam;
    delete mouse;
    delete tunnel;
    delete obstacle;
}

void SensorHandler::UpdateAllSensors()
{
    cam->UpdateSensors();
    mouse->UpdateSensors();
    tunnel->UpdateSensors();
    obstacle->UpdateSensors();
}