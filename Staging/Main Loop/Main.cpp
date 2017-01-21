#include "SensorHandler.h"
#include "Localization.h"
#include "StateDetect.h"
#include "Navigation.h"

int main()
{
    SensorHandler* SensorControl = new SensorHandler();
    Localization* Localizer = new Localization();
    StateDetect* StateDetector = new StateDetect();
    Navigation* Navigator = new Navigation();

    while (true)
    {
        int state = -1;
        pair currentPosition;

        // SensorHandler
        SensorControl->UpdateAllSensors();


        // Localization....useless?
        Localizer->setCurrentPos(SensorControl->getMouseSensor()->getValue());
        currentPosition = Localizer->getCurrentPos();


        // Assessments
        state = StateDetector->DetermineState(SensorControl);


        // Navigation
        Navigator->DetermineNavigation(state, SensorControl);

    }
    return 0;
}