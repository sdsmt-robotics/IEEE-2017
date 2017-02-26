#include "easy_serial.h"

int serial_port_init(const char* serialport, int baud)
{
    struct termios toptions;

    int fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd <= 0)
    {
        printf("Can't open serial port!");
        return -1;
    }
    speed_t brate = baud;

    switch(baud)
    {
    case 4800:
        brate=B4800;
        break;
    case 9600:
        brate=B9600;
        break;
    case 19200:
        brate=B19200;
        break;
    case 38400:
        brate=B38400;
        break;
    case 57600:
        brate=B57600;
        break;
    case 115200:
        brate=B115200;
        break;
    }
    cfsetispeed(&toptions, brate);
    cfsetospeed(&toptions, brate);
    // 8N1
    toptions.c_cflag &= ~PARENB;
    toptions.c_cflag &= ~CSTOPB;
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;
    // no flow control
    toptions.c_cflag &= ~CRTSCTS;
    toptions.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
    toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
    toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    toptions.c_oflag &= ~OPOST; // make raw
    toptions.c_cc[VMIN]  = 0;
    toptions.c_cc[VTIME] = 1;
    return fd;
}
/*
    Dump anything buffered to junk
*/
void clear_port(int port)
{
    int n = 1;
    char nothing = 0;
    while(n > 0)
        n = read(port, &nothing, 1);
    return;
}
