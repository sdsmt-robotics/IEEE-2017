#include "Ping.h"

Ping::Ping(std::string Name)
{
    for (unsigned int i = 0; i < 10; ++i)
        values[i] = StartV;
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
	memcpy(&values[walker], packet.data, sizeof(double));
	value = 0.0f;
	for (unsigned int i = 0; i < 10; ++i)
		value += values[i];
	value = value/10.0f;

	if (value < DETECTED)
		detected = true;
	else
		detected = false;

	if (walker < 9)
		++walker;
	else
		walker = 0;
}