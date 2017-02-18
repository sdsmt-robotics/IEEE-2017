#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "mouse.h"

using namespace std;

class FileHandler
{
public:
    FileHandler(const string filename, bool read=true);
    ~FileHandler();

    void Write(point_t location);
    point_t Read();

private:
    int file_descriptor;

    size_t ReadBlocking(char* buffer, size_t bytes);
};
