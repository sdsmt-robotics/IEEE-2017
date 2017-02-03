#include "Arduino.h"
#include "Packet.h"

int main(int argc, char const *argv[])
{

    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <send device> <receive device> <baudrate>\n", argv[0]);
        fprintf(stderr, "Example: %s /dev/ttyACM0 /dev/ttyUSB0 115200\n", argv[0]);
        exit(0);
    }

    Arduino arduino = Arduino(argv[1], argv[2], atoi(argv[3]));

    string input = "";
    // leave one byte for the null terminator
    char c_input[DATA_SIZE + 1] = {0};
    char output_data[DATA_SIZE] = {0};
    Command c;

    while(true)
    {
        cout << "input> ";
        //`cin` tokenizes on whitespace, use getline instead
        getline(cin, input);
        memcpy(c_input, input.c_str(), (input.length() <= 8) ? (input.length()) : (8));

        // note that this only packs DATA_SIZE bytes of the input. If we give
        // it less than DATA_SIZE bytes bad things happen.
        packet_t packet = pack(NONE, (uint8_t*) c_input);
        cout << "Raw binary sent:" << endl;
        print_bits(PACKET_SIZE, &packet);

        size_t wrote = arduino.Send(packet);

        usleep(5000);

        // note that the received data will only be DATA_SIZE bytes plus a
        // single byte for the command
        packet = arduino.Receive();
        cout << "Raw binary received:" << endl;
        print_bits(PACKET_SIZE, &packet);


        unpack(packet, c, (uint8_t*) output_data);

        cout << "wrote " << wrote <<"> " << c_input << endl;
        cout << "read   > " << output_data << endl;

        memset(c_input, 0, DATA_SIZE+1);
        memset(output_data, 0, DATA_SIZE);
        memset(&packet, 0, PACKET_SIZE);
    }
    return 0;
}
