#include "Ping.h"

Ping::Ping(std::string Name)
{
    for (int i = 0; i < 10; ++i)
        values[i] = STV;
    setName(Name);
}

void Ping::UpdateSensors()
{	
	packet_t packet;
	packet.command = SENSOR_PING;
	packet = ardy->getPacket(packet);
	InterpretValue();
}

void Ping::InterpretValue()
{
	memcpy(&value, packet.data, sizeof(double));
}