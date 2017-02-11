#include "globals.h"
#include "constants.h"

uint8_t input[DATA_SIZE] = {0};
uint8_t header_buffer[ENUM_SIZE] = {0};
Header header = NONE;
bool packet_received = false;

void setup()
{
    // Initialize the two serial ports:
    in->begin(115200);
    out->begin(115200);

}

void loop()
{
    if (in->available() > 0)
    {
        // There is no logic here to correct any offsets -- say we lose a byte
        // then there is no logic here to detect and correct that. The proper
        // method would be some kind of Hamming code and/or checksum
        // That's not something I'm super familiar with, and since doing it
        // this way worked just fine last year, I'll go with this for now.

        // read in the first two packet bytes (header/command/metadata)
        for (int i = 0; i < ENUM_SIZE; i++)
        {
            // makes sure there's something to read
            while(!in->available() > 0) {}
            header_buffer[i] = in->read();
        }
        memcpy(&header, header_buffer, ENUM_SIZE);

        // read in the next DATA_SIZE bytes (packet data)
        for (int i = 0; i < DATA_SIZE; i++)
        {
            // makes sure there's something to read
            while(!in->available() > 0) {}
            input[i] = in->read();
        }

        // in last year's code we had a bool flag to tell us when we were done receiving a packet.
        // The way it stands now, the only way we exit the above loop is *if* we've received an
        // entire packet.

        // packet_received = true;

        noInterrupts();
        switch(header)
        {
        case NONE:
            break;
        case ERROR:
            break;
        case IDLE:
            break;
        case DATA:
            break;
        case PIP_DATA:
            break;
        case MAP_DATA:
            break;
        case SENSOR_REQUEST:
            break;
        case SENSOR_RESPONSE:
            break;
        case MOTOR_DUAL:
            break;
        case MOTOR_LEFT:
            break;
        case MOTOR_RIGHT:
            break;
        case MOTOR_DUAL_STEPS:
            break;
        case MOTOR_LEFT_STEPS:
            break;
        case MOTOR_RIGHT_STEPS:
            break;
        case SERVO_RAISE:
            break;
        case SERVO_LOWER:
            break;
        default:
            break;
        }

        // For debugging purposes, echo the packet we just received back to the Odroid
        echo_packet(header, input);

        // We've finished with that packet; go looking for a new one.
        header = NONE;
        memset(input, 0, DATA_SIZE);
        memset(header_buffer, 0, ENUM_SIZE);
        // packet_received = false;

        interrupts();
    }
}

// literally reads and dumps everything in the serial buffer
void clear_buffer()
{
    uint8_t nothing;
    while(in->available() > 0)
    {
        nothing = in->read();
    }
}

// simple function for printing the input string. useful for troubleshooting
void echo_packet(Header header, uint8_t* input)
{
    out->write((char*) &header, ENUM_SIZE);
    for(int i = 0; i < DATA_SIZE; i++)
    {
        out->write(input[i]);
    }
}



