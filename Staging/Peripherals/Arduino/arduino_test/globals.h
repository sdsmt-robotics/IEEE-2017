#ifndef GLOBALS_H
#define GLOBALS_H

////////////////////////////////////////////////////////////////////////////////
//    Global Objects
////////////////////////////////////////////////////////////////////////////////
extern HardwareSerial *in = &Serial;
extern HardwareSerial *out  = &Serial1;

// FTDI cable on an ATmega for Serial1 can be plugged in as shown here:
// https://www.arduino.cc/en/Tutorial/MultiSerialMega
// Specifically, red and black FTDI cables get plugged into 5V and GND respectively,
// and Orange and Brown cables get plugged into pins 19 and 18 respectively.

#endif /* end of include guard: GLOBALS_H */



