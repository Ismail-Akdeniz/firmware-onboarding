#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{

public:
    BMESPIInterface() : sensor(BMEConstants::cspin, BMEConstants::mosipin, BMEConstants::misopin, BMEConstants::sckpin) {}
    void init();
    float get_temperature();

private:
    Adafruit_BME280 sensor;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;