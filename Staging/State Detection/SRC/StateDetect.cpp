#include "StateDetect.h"

void StateDetect::DetermineState(SensorHandler* SensorControl, Localization* Loco, std::pair<float, float> dest)
{
    // Yeah....Need to make a state machine for this guy
    int direction = Direction(Loco);
    if (direction == -1)
    {
    	state = -1;
    	return;
    }

	if (Avoiding())
	{
		// Determine if done
		if (direction == 0 && state % 10 == 0)
		{
			state -= 20;
			return;
		}

		// Continue avoiding

	}
	else if (SensorControl->ping[direction - 1]->getDetected())
	{
		// Lay in new course
		state += 20;			// Defines "avoiding" state
		state += direction;		// Navigation needs to set route, navigation removes value after RESOLVED
	}
	else if (OnCourse(Loco->getCurrentPos(), dest, direction))	// X
	{
		return;
	}
}

int StateDetect::Direction(Localization* Loco)
{
	// Decode direction.
	// 0 = Stopped
	// 1 = Forward
	// 2 = Backward
	// 3 = Right
	// 4 = Left
	// -1  = ERROR

	std::pair<float, float> curPos = Loco->getCurrentPos();
	std::pair<float, float> prevPos = Loco->getPreviousPos();
	if (Equal(prevPos.first, curPos.first))
		return 0;

	if (prevPos.first < curPos.first)
		return 1;

	if (prevPos.first > curPos.first)
		return 2;

	if (prevPos.second < curPos.second)
		return 3;

	if (prevPos.second > curPos.second)
		return 4;

	return -1;
}


bool StateDetect::Equal(const float &lhs, const float &rhs) const
{
	return fabs(lhs - rhs) < 0.001;
}


bool StateDetect::Avoiding()
{
	return (state % 100 - state % 10 == 2);
}

bool StateDetect::OnCourse(std::pair<float, float> cur, std::pair<float, float> dest, int XorY)
{
	if (XorY == 1 || XorY == 2)
		return Equal(cur.first, dest.first);

	return Equal(cur.second, dest.second);
}