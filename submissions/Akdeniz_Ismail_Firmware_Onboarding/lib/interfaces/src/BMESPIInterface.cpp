#include "BMESPIInterface.h"

void BMESPIInterface::init()
{
    sensor.init();
    sensor.setSampling();
}
float BMESPIInterface::get_temperature()
{
    return sensor.readTemperature();
}