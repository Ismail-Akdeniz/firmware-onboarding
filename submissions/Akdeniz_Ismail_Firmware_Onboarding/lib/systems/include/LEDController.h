#pragma once
#include "etl/singleton.h"

class LEDController {

public:
    LEDController() = default;
    float calculate(float temperature, float old_temperature, float blinkrate);
};

using LEDControllerInstance = etl::singleton<LEDController>;