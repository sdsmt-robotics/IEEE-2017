#ifndef STATEDETECT_H
#define STATEDETECT_H

#include "SensorHandler.h"
#include <math.h>

class StateDetect{
public:
    // Getters
	int getState(){return state; };
    // Setters

    // Actions
    void DetermineState(SensorHandler* SensorControl, PIDControl* PID);
    

private:
	// state is a 3 digit number that represents the state
	// 100's place represents direction
	// 10's place represents avoidance, lid removal, pip count, etc.
	// 1's place represents status of task defined by 10's place (0 means done).

	int state = 0;
	int Direction(Localization* Loco);
	bool Equal(const float &lhs, const float &rhs) const;	// inline?
	bool OnCourse(std::pair<float, float> cur, std::pair<float, float> dest, int XorY);
};

#endif