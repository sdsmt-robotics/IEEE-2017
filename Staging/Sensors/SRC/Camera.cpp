#include "Camera.h"

Camera::Camera(std::string Name)
{
    setName(Name);
    // Initialize camera
}

Camera::~Camera()
{
    // Unintialize camera
}

int Camera::ReadCamera()
{
    // Insert function call to Kali's code
    countedPips = true;
    //value = pips;
    return 0;
}

void Camera::UpdateSensors()
{
    // Does NOTHING unless it is at the specific state of camera over
    // open lid
    value = ReadCamera();

    // ends with updating "value"
}