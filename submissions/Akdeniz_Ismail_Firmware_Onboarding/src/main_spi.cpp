#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"

BMESPIInterface interface;
LEDController controller;
unsigned int blinkrate = 1000;
unsigned int old_temperature = 20;
unsigned int temp = 20;

void blink(unsigned int ms);

void setup()
{
  pinMode(BMEConstants::ledpin, OUTPUT);
  digitalWrite(BMEConstants::ledpin, LOW);
  BMESPIInterface interface = BMESPIInterface();
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