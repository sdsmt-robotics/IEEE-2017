#include "Packet.h"

// Given a command and data, construct a packet_t
packet_t Pack(Header command, uint8_t* data)
{
    packet_t packet;
    memset(&packet, 0, PACKET_SIZE);

    packet.command = command;
    // copy DATA_SIZE bytes from data to packet.data
    memcpy(&packet.data, data, DATA_SIZE);
    return packet;
}

// Given a packet_t, unpack its contents into command and data
void Unpack(packet_t packet, Header& command, uint8_t* data)
{
    command = packet.command;
    memcpy(data, &packet.data, DATA_SIZE);
}

// clears the packet's data
void ClearPacket(packet_t &packet)
{
    packet.command = NONE;
    memset(packet.data, 0, DATA_SIZE);
}

// Prints the bits of an arbitrary object, given a pointer and its size in
// bytes. Assumes little endian.
void PrintBits(const size_t size, const void* ptr)
{
    uint8_t *b = (uint8_t*) ptr;
    uint8_t byte;
    int i, j;

    for (i = size - 1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            byte = b[i] & (1 << j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    printf("\n");
}
