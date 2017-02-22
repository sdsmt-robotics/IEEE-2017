#include "Sensors.h"

Sensor::Sensor(Arduino *A)
{
	ardy = A;
	data = new uint8_t();	// Why is this here...Austin?
}

Sensor::~Sensor()
{
	delete data;
}

//void Sensor::UpdateSensors()
//{
//
//}