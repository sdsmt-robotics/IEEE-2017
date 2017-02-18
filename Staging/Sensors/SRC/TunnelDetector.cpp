#include "TunnelDetector.h"

TunnelDetector::TunnelDetector(std::string Name)
{
    setName(Name);
    // Make initialization if necessary, else delete
}

void TunnelDetector::UpdateSensors()
{
	packet_t packet;
	packet.command = SENSOR_TUNNELDETECTOR;	// Have to set up this enum
	packet = ardy->getPacket(packet);
	InterpretValue();
    // ends with updating "value"
}

void TunnelDetector::InterpretValue()
{
	memcpy(&value, packet.data, sizeof(bool));	// sizeof is the datatype of value

}