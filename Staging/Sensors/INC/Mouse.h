#ifndef MOUSE_H
#define MOUSE_H

#include "Sensors.h"

class Mouse : Sensor{
public:
    Mouse(std::string Name);

    // Getters
    std::pair<int, int> getValue(){ return value; };

    // Setters
    void setValue(int x, int y){ value = std::make_pair(x, y); };

    // Actions
    void UpdateSensors();

private:
	void InterpretValue();
    std::pair<int, int> value = std::make_pair(0,0);

};



#endif