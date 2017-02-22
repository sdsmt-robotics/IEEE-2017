#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <utility>

typedef std::pair<float, float> pair;


class Localization{
public:
    Localization();

    // Getters
    std::pair<float, float> getCurrentPos(){ return currentPos; };
    std::pair<float, float> getPreviousPos(){ return previousPos; };

    // Setters
    void setCurrentPos(std::pair<float, float> curPos);

    // Actions

    
private:
	std::pair<float, float> previousPositions[5];	// Number based on reads/second
	int walker = 0;
	std::pair<float, float> previousPos;
    std::pair<float, float> currentPos;
};

#endif