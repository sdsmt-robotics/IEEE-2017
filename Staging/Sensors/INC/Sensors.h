#ifndef SENSORS_H
#define SENSORS_H

#include <string>

class Sensor{
public:
    Sensor();
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

private:
    std::string name = "";
    bool isActive = false;
};


#endif