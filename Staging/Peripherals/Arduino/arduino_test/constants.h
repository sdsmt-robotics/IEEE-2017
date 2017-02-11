#pragma once
#pragma pack (1) // force g++ to pack structs (no padding)

// Enums on the Arduino are two bytes
const size_t ENUM_SIZE = 2;
// size of the data portion of the packet in bytes
const size_t DATA_SIZE = 8;

// Arduino enums are two bytes, so we set the size of the enum to be 2 bytes on the g++ side.
enum Header
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

// This is a project specific packet implementation
struct packet_t
{
    // two bytes
    Header command;

    // DATA_SIZE bytes
    uint8_t data[DATA_SIZE];
};

const size_t PACKET_SIZE = sizeof(packet_t);

// Enums are 2 bytes on the Arduino, make damn sure they're 2 bytes here.
static_assert(sizeof(Header) == ENUM_SIZE, "Enum not 2 bytes");

// make damn sure that a packet_t is the size we want
// DATA_SIZE bytes of data and a 2 byte enum
static_assert(PACKET_SIZE == DATA_SIZE + ENUM_SIZE, "packet_t struct unexpected size");

