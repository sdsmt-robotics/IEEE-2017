#include "Packet.h"

// Given a command and data, construct a packet_t
packet_t pack(Command command, uint8_t* data)
{
    packet_t packet;
    memset(&packet, 0, PACKET_SIZE);
    // the Command enums index the COMMANDS array in Packet.h
    packet.command = COMMANDS[command];
    // copy DATA_SIZE bytes from data to packet.data
    memcpy(&packet.data, data, DATA_SIZE);
    return packet;
}

// Given a packet_t, unpack its contents into command and data
void unpack(packet_t packet, Command& command, uint8_t* data)
{
    // find the index (Command) of packet.command in the COMMANDS array
    const size_t index = std::find(COMMANDS, COMMANDS+NUM_COMMANDS, packet.command) - COMMANDS;

    if (index != NUM_COMMANDS)
    {
        // we found a Command corresponding to the given byte
        // convert the integer index to a Command
        command = static_cast<Command>(index);
    }
    else
    {
        // bad things happened
        command = ERROR;
    }

    memset(data, 0, DATA_SIZE);
    memcpy(data, &packet.data, DATA_SIZE);
}

// Prints the bits of an arbitrary object, given a pointer and its size in
// bytes. Assumes little endian.
void print_bits(const size_t size, const void* ptr)
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
