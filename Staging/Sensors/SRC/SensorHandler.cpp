#include "SensorHandler.h"

SensorHandler::SensorHandler()
{
    cam = new Camera("Camera");
    mouse = new Mouse("Mouse");
    tunnel = new TunnelDetection("Tunnel Detector");
    obstacle = new Obstacle("Obstacle Detector");
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