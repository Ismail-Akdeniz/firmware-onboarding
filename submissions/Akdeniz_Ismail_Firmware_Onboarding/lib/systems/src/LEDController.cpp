#include "LEDController.h"


float LEDController::calculate(float temperature, float old_temperature, float blinkrate)
{
    if (temperature < old_temperature)
    {
        blinkrate = blinkrate + 5;
    }
    else
    {
        blinkrate = blinkrate - 5;
    }
    return blinkrate;
}