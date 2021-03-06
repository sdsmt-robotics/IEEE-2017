#include "Arduino.h"

Arduino::Arduino(string send, string receive, int baud)
{
    this->send = new Serial(send, baud);
    this->receive = new Serial(receive, baud);
}

Arduino::~Arduino()
{
    delete this->send;
    delete this->receive;
}

ssize_t Arduino::Send(packet_t packet)
{
    char* buffer = (char*) malloc(PACKET_SIZE);
    memset(buffer, 0, PACKET_SIZE);

    // fill buffer with the raw packet data
    memcpy(buffer, &packet, PACKET_SIZE);

    // send the buffer to the arduino
    ssize_t temp = this->send->Write(buffer, PACKET_SIZE);

    free(buffer);
    return temp;
}

packet_t Arduino::Receive()
{
    void* buffer = malloc(PACKET_SIZE);
    memset(buffer, 0, PACKET_SIZE);
    packet_t packet;
    memset(&packet, 0, PACKET_SIZE);

    // receive data from the arduino and fill the buffer with it
    size_t received = this->receive->ReadBlocking((char*)buffer, PACKET_SIZE);
    received += 1; // make g++ stop complaining about unused variables

    // construct a packet with the raw data
    memcpy(&packet, buffer, PACKET_SIZE);

    free(buffer);
    return packet;
}
