#ifndef SENSORS_H
#define SENSORS_H

#include "../../Peripherals/Adruino/Arduino.h"
#include <string>

class Sensor{
public:
    Sensor(Arduino *A);
    ~Sensor();
    // Getters
    std::string getName(){ return name; };    
    bool getIsActive(){ return isActive; };

    // Setters
    void setName(std::string s){ name = s; };    
    void setIsActive(bool a){ isActive = a; };

    // Actions
//protected:
    virtual void UpdateSensors() = 0;
    virtual void InterpretValue() = 0;

private:
    std::string name = "";
    bool isActive = false;
    ardy* = nullptr;
    packet_t packet;
};


#endif