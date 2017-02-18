#include "mouse.h"
#include "FileHandler.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <data file>\n", argv[0]);
        fprintf(stderr, "Example: %s ~/.mouse\n", argv[0]);
        exit(0);
    }

    FileHandler read_handler = FileHandler(argv[1], true);

    while (true)
    {
        point_t read_location = read_handler.Read();
        cout << "(x, y) = (" << read_location.x << ", " << read_location.y << ")" << endl;
    }

    return 0;
}
