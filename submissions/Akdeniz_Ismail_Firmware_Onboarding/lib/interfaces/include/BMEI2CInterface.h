#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{

public:
    BMEI2CInterface() : sensor() {};
    void init();
    float get_temperature();

private:
    Adafruit_BME280 sensor;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;