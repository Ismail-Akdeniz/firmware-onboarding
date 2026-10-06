#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

BMEI2CInterface interface;
LEDController controller;
unsigned int blinkrate = 1000;
unsigned int old_temperature = 20;
unsigned int temp = 20;

void blink(unsigned int ms);

void setup()
{
    pinMode(BMEConstants::ledpin, OUTPUT);
    digitalWrite(BMEConstants::ledpin, LOW);
    BMEI2CInterface interface = BMEI2CInterface();
    interface.init();
}

void loop()
{
    temp = interface.get_temperature();
    blink(controller.calculate(temp, old_temperature, blinkrate));
    blinkrate = controller.calculate(temp, old_temperature, blinkrate);
    old_temperature = temp;
}

void blink(unsigned int ms)
{
    digitalWrite(BMEConstants::ledpin, HIGH);
    delay(ms);
    digitalWrite(BMEConstants::ledpin, LOW);
    delay(ms);
}