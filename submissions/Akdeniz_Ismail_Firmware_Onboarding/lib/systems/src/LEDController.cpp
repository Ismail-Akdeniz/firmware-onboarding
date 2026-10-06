#include "LEDController.h"


float LEDController::calculate(float temperature, float old_temperature, float blinkrate)
{
    if (temperature < old_temperature)
    {
        blinkrate = blinkrate - 100;
    }
    else
    {
        blinkrate = blinkrate + 100;
    }
    return blinkrate;
}