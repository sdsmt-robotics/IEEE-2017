#include "mouse.h"

Mouse::Mouse(const string file_name)
{
    // open file as read only and set this->file_descriptor
    this->file_descriptor = open(file_name.c_str(), O_RDONLY);
    this->current_location.x = 0;
    this->current_location.y = 0;
}

Mouse::~Mouse()
{
    // close this->file_descriptor
    close(this->file_descriptor);
}

point_t Mouse::getLocation()
{
    return this->current_location;
}

void Mouse::Update()
{
    // the PS/2 status is 3 bytes.
    uint8_t buffer[3] = {0};
    int8_t delta_x = 0;
    int8_t delta_y = 0;

    // perform a blocking 3 byte read and update the appropriate values
    this->ReadBlocking((char*) buffer, 3);

    // buffer now contains the PS2 3 byte status struct
    // byte 1 contains the status (we're not using)
    // byte 2 contains the delta x
    // byte 3 contains the delta y

    memcpy(&delta_x, buffer + 1, sizeof(uint8_t));
    memcpy(&delta_y, buffer + 2, sizeof(uint8_t));

    this->current_location.x += delta_x;
    this->current_location.y += delta_y;
}

size_t Mouse::ReadBlocking(char* buffer, size_t bytes)
{
    // let's hope the user passes in an appropriate number of bytes
    bzero(buffer, bytes);
    size_t bytes_read = 0;
    // it's important that tmp be `ssize_t` rather than `size_t`
    // as `ssize_t` can be *signed* -- read returns -1 if it didn't read
    // anything...
    ssize_t tmp = 0;

    // try to read bytes number of bytes
    while(bytes_read < bytes)
    {
        // offset the buffer the appropriate amount so we don't overwrite
        // something we've already written
        tmp = read(this->file_descriptor, buffer + bytes_read, bytes - bytes_read);

        if (tmp > 0)
        {
            bytes_read += tmp;
        }
    }

    return bytes_read;
}
