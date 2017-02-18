#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

// a point struct
struct point_t
{
    int x;
    int y;
};

class Mouse
{
public:
    Mouse(const string file_name);
    ~Mouse();

    void Update();
    point_t getLocation();

private:
    int file_descriptor;
    point_t current_location;

    size_t ReadBlocking(char* buffer, size_t bytes);
};
