#include "SampleSensor.h"

SampleSensor::SampleSensor(std::string Name)
{
    setName(Name);
}

void SampleSensor::UpdateSensors()
{
	packet_t packet;
	packet.command = SENSOR_SAMPLESENSOR;	// Have to set up this enum
	packet = ardy->getPacket(packet);
	InterpretValue();
    // ends with updating "value" (inherited from Sensor class)
}

void SampleSensor::InterpretValue()
{
	memcpy(&value, packet.data, sizeof(int));	// sizeof is the datatype of value

}