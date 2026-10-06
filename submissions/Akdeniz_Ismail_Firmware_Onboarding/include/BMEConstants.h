#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    const uint8_t i2c_address = 0x77;
    const int cspin = 10;
    const int mosipin = 11;
    const int misopin = 12;
    const int sckpin = 13;
    const int ledpin = 5;
}