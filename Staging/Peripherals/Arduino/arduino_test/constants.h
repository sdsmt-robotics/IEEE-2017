#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Arduino.h"

#define NONE 0x10
#define ERROR 0x11
#define IDLE 0x12
#define DATA 0x20
#define PIP_DATA 0x21
#define MAP_DATA 0x22
#define SENSOR_REQUEST 0x30
#define SENSOR_RESPONSE 0x40
#define MOTOR_DUAL 0x50
#define MOTOR_LEFT 0x51
#define MOTOR_RIGHT 0x52
#define MOTOR_DUAL_STEPS 0x60
#define MOTOR_LEFT_STEPS 0x61
#define MOTOR_RIGHT_STEPS 0x62
#define SERVO_RAISE 0x70
#define SERVO_LOWER 0x71

// an array of command bytes indexed by the Command enum
const size_t NUM_COMMANDS = 16;

// size of the data portion of the packet in bytes
const size_t DATA_SIZE = 8;

// This is a project specific packet implementation
struct packet_t
{
    // one byte, without #pragma pack (1), this would be 4ish
    // bytes to allign the addresses (it's up to the compiler how it packs)
    uint8_t command;

    // DATA_SIZE bytes
    uint8_t data[DATA_SIZE];
};

const size_t PACKET_SIZE = sizeof(packet_t);

static_assert(sizeof(packet_t) == DATA_SIZE + 1, "packet_t struct unexpected size");

packet_t pack(uint8_t command, uint8_t* data);
void unpack(packet_t packet, uint8_t& command, uint8_t* data);

#endif /* end of include guard: CONSTANTS_H */


