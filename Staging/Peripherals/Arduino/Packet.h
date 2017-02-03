#pragma once
#pragma pack (1) // force g++ to pack structs (no padding)

#include <iostream>
#include <cstring>
#include <algorithm>

// maybe this stuff goes in a globals/defines header?S
enum Command
{
    NONE,
    ERROR,
    IDLE,
    DATA,
    PIP_DATA,
    MAP_DATA,
    SENSOR_REQUEST,
    SENSOR_RESPONSE,
    MOTOR_DUAL,
    MOTOR_LEFT,
    MOTOR_RIGHT,
    MOTOR_DUAL_STEPS,
    MOTOR_LEFT_STEPS,
    MOTOR_RIGHT_STEPS,
    SERVO_RAISE,
    SERVO_LOWER,
};

// an array of command bytes indexed by the Command enum
const size_t NUM_COMMANDS = 16;
const uint8_t COMMANDS[NUM_COMMANDS] =
{
    0x0, // NONE
    0x11, // ERROR
    0x12, // IDLE
    0x20, // DATA
    0x21, // PIP_DATA
    0x22, // MAP_DATA
    0x30, // SENSOR_REQUEST
    0x40, // SENSOR_RESPONSE
    0x50, // MOTOR_DUAL
    0x51, // MOTOR_LEFT
    0x52, // MOTOR_RIGHT
    0x60, // MOTOR_DUAL_STEPS
    0x61, // MOTOR_LEFT_STEPS
    0x62, // MOTOR_RIGHT_STEPS
    0x70, // SERVO_RAISE
    0x71, // SERVO_LOWER
};

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

// make damn sure that a packet_t is the size we want
// DATA_SIZE bytes of data and a single command/header byte
static_assert(sizeof(packet_t) == DATA_SIZE + 1, "packet_t struct unexpected size");

packet_t pack(Command command, uint8_t* data);
void unpack(packet_t packet, Command& command, uint8_t* data);
void print_bits(size_t const size, void const * const ptr);
