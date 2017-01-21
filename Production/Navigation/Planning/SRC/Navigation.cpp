#include "Navigation.h"

/*  This will be hardcoded because these are the 14 points where we will make turns.
    These are the destination locations as well as used for identifying when we must turn.
*/
const std::pair<int, int> Navigation::turnPoints[14] =
{ std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2),
std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2),
std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2), std::make_pair(1, 2),
std::make_pair(1, 2), std::make_pair(1, 2) };



/*  Checks to see if we are within arbitrary distance of the turn point,
    if we are it will return true, else false;
*/
bool Navigation::OnTurnPoint(int x, int y)
{
    if (turnPoints[nextPoint].first > x + TPTOLLERANCE || turnPoints[nextPoint].first < x - TPTOLLERANCE)
        if (turnPoints[nextPoint].second > y + TPTOLLERANCE || turnPoints[nextPoint].second < y - TPTOLLERANCE)
            return true;
    return false;
}




/*  Returns the current destination / next turn point
*/
std::pair<int, int> Navigation::getDestination()
{
    return turnPoints[nextPoint];
}


/*  Called after initializing the turn
*/
void Navigation::setNextPoint()
{
    ++nextPoint;
}



void Navigation::DetermineNavigation(int state, SensorHandler* SensorControl)
{

}