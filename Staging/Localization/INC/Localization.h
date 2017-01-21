#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <utility>

typedef std::pair<int, int> pair;


class Localization{
public:
    Localization();

    // Getters
    pair getCurrentPos(){ return currentPos; };

    // Setters
    void setCurrentPos(pair curPos){ currentPos = std::make_pair(curPos.first, curPos.second); };

    // Actions

    
private:
    pair currentPos;

};

#endif