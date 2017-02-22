#include "SensorHandler.h"
#include "Localization.h"
#include "StateDetect.h"
#include "Navigation.h"

int main()
{
    SensorHandler* SensorControl = new SensorHandler();
    Localization* Localizer = new Localization();
    StateDetect* StateDetector = new StateDetect(SensorControl, Localizer);
    Navigation* Navigator = new Navigation();

    std::pair<float, float> curDestination = Localizer->getCurrentPos();

    while (true)
    {
        int state = -1;
        

        // SensorHandler
        SensorControl->UpdateAllSensors();


        // Localization....useless?
        Localizer->setCurrentPos(SensorControl->getMouseSensor()->getValue());


        // Assessments
        state = StateDetector->DetermineState(SensorControl, Localizer);


        // Navigation
        Navigator->DetermineNavigation(state, SensorControl);
        curDestination = Navigator->getDestination();
    }
    return 0;
}