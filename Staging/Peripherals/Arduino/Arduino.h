#pragma once
#include <iostream>
#include <cstring>
#include "Packet.h"
#include "../Serial/Serial.h"  // TODO: change makefile et al to allow #include "Serial.h"

using namespace std;

// Rationale: This is a project specific wrapper around the general Serial
// class. This Sends and receives `packet_t` structs defined in `Packet.h`
class Arduino
{
public:
    Arduino(string send, string receive, int baud);
    ~Arduino();
    ssize_t Send(packet_t packet);
    packet_t Receive();
    packet_t GetPacket(packet_t packet);

private:
    Serial* send;
    Serial* receive;
};
