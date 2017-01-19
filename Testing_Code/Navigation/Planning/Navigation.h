#ifndef NAVIGATION_H
#define NAVIGATION_H

#define TPTOLLERANCE 5   // Arbitrary tollerance for turn points

#include <utility>
#include "SensorHandler.h"

class Navigation{
public:
    
    // Getters
    std::pair<int, int> getDestination();

    // Setters
    void setNextPoint();    // Be mindful of obstacles on turns

    // Actions
    void AvoidObstacle();
    bool OnTurnPoint(int x, int y);     // get x & y from mouse or Localization
    void DetermineNavigation(int s, SensorHandler* SensorControl);

private:
    int nextPoint = 0;
    static const std::pair<int, int> turnPoints[14];


    // May need to keep a boolean while on a turning point so we don't have race conditions 
    // or other issues. We will need to test if it's necessary.
};


#endif