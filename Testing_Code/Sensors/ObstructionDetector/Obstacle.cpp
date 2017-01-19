#include "Obstacle.h"

Obstacle::Obstacle(std::string Name)
{
    for (int i = 0; i < 10; ++i)
        values[i] = STV;
    setName(Name);
}

void Obstacle::UpdateSensors()
{

    // ends with updating "value"
}