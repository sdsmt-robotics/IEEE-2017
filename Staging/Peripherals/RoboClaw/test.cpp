#include "RoboClaw.h"
#include <iostream>

// packet serial mode 7
#define address 0x80

using namespace std;

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        fprintf(stderr, "Usage:   %s <roboclaw serial device> <timeout>\n", argv[0]);
        fprintf(stderr, "Example: %s /dev/ttyACM0 10000\n", argv[0]);
        exit(0);
    }

    RoboClaw controller = RoboClaw(argv[1], atoi(argv[2]));
    // returns 1 on failure
    controller.begin(115200);

    while (true)
    {

        // Use commands 0 - 7 on page 48-49 in the documentation.

        // Look at 41-43 on page 77-78 in documentation.
        cout << "test" << endl;
        cout << controller.ForwardBackwardM2(address, 64) << endl;
        cout << controller.ForwardBackwardM1(address, 0) << endl;
        sleep(1);

        cout << controller.ForwardBackwardM1(address, 64) << endl;
        cout << controller.ForwardBackwardM2(address, 127) << endl;
        sleep(1);
    }

    return 0;
}
