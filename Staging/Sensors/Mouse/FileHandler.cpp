#include "FileHandler.h"

FileHandler::FileHandler(const string file_name, bool read)
{
    // opening file for reading
    if (read)
    {
        this->file_descriptor = open(file_name.c_str(), O_RDONLY);
    }
    // opening file for writing
    else
    {
        // create the file if it doesn't exist. Create it with read access for everyone
        // Don't add to the end of the file, update it in place.
        this->file_descriptor = open(file_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IROTH);
    }
}

FileHandler::~FileHandler()
{
    close(this->file_descriptor);
}

void FileHandler::Write(point_t location)
{
    char buffer[sizeof(point_t)] = {0};
    memcpy(buffer, &location, sizeof(point_t));
    ssize_t n = write(this->file_descriptor, buffer, sizeof(point_t));
    // seek to the beginning of the file immediately after accessing/writing data
    lseek(this->file_descriptor, 0, SEEK_DATA);
    // make g++ stop complaining
    n += 1;
}

point_t FileHandler::Read()
{
    char buffer[sizeof(point_t)] = {0};
    point_t location;
    size_t n = this->ReadBlocking(buffer, sizeof(point_t));
    // seek to the beginning of the file immediately after accessing/writing data
    lseek(this->file_descriptor, 0, SEEK_DATA);
    // make g++ stop complaining
    n += 1;
    memcpy(&location, buffer, sizeof(point_t));
    return location;
}

size_t FileHandler::ReadBlocking(char* buffer, size_t bytes)
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
