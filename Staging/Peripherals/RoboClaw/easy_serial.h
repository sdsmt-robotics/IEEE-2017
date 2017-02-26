#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <getopt.h>
/*
    This file provides a simple, easy-to-use interface
    for using serial ports.
*/
/*
    This function just takes ina  location, and a baud rate, and
    then attempts to open the port for async serial read/write
*/

int serial_port_init(const char* serialport, int baud);
void clear_port(int port);
