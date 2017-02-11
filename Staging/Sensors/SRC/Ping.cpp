#include "Ping.h"

Obstacle::Obstacle(std::string Name)
{
    for (int i = 0; i < 10; ++i)
        values[i] = STV;
    setName(Name);
}

void Obstacle::UpdateSensors()
{	
	packet_t packet;
	packet.command = SENSOR_PING;
	packet = ardy->getPacket(packet);
	InterpretValue();
}

void Obstacle::InterpretValue()
{
	memcpy(&value, packet.data, sizeof(double));
}