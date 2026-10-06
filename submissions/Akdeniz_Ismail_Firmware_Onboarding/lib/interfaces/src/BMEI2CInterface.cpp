#include "BMEI2CInterface.h"

void BMEI2CInterface::init()
{
    sensor.begin(BMEConstants::i2c_address);
    sensor.setSampling();
}
float BMEI2CInterface::get_temperature()
{
    return sensor.readTemperature();
}