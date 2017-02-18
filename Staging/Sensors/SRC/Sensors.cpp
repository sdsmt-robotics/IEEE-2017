#include "Sensors.h"

Sensor::Sensor(Arduino *A)
{
	ardy = A;
	data = new uint8_t();
}

Sensor::~Sensor()
{

}

//void Sensor::UpdateSensors()
//{
//
//}