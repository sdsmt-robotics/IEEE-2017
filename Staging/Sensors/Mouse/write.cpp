#include "mouse.h"
#include "FileHandler.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <mouse file> <data file>\n", argv[0]);
        fprintf(stderr, "Example: %s /dev/input/mice ~/.mouse\n", argv[0]);
        exit(0);
    }

    Mouse mouse = Mouse(argv[1]);
    FileHandler write_handler = FileHandler(argv[2], false);

    while (true)
    {
        // pull updates from Mouse as often as possible
        // Update blocks until it has read 3 bytes from the mouse file
        mouse.Update();
        point_t current_location = mouse.getLocation();
        write_handler.Write(current_location);
    }

    return 0;
}
