#include "Localization.h"

Localization::Localization()
{
    for (unsigned int i = 0; i < 5; ++i)
    	previousPositions[i] = std::make_pair(0.0f, 0.0f);
}

void Localization::setCurrentPos(std::pair<float, float> curPos)
{
	float x = 0.0f;
	float y = 0.0f;
	for (unsigned int i = 0; i < 5; ++i)
	{
    	x += previousPositions[i].first;
    	y += previousPositions[i].second;
	}

	previousPos = std::make_pair(x/5.0f, y/5.0f);
	currentPos = std::make_pair(curPos.first, curPos.second);
	previousPositions[walker] = currentPos;

	if (walker < 4)
		++walker;
	else
		walker = 0;
}
