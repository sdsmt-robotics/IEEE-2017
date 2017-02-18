#include "Mouse.h"

Mouse::Mouse(std::string Name)
{
    setName(Name);
    // Make initialization if necessary, else delete
}

void Mouse::UpdateSensors()
{
	packet_t packet;
	packet.command = SENSOR_MOUSE;
	packet = ardy->getPacket(packet);
	InterpretValue();
}

void Mouse::InterpretValue()
{
	// Need to test this, it may not like std::pair<int, int>...we may have to play
	// around with a struct or something
	memcpy(&value, packet.data, sizeof(std::pair<int, int>));

}