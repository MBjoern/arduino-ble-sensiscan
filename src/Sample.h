/*
 Sample.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_SAMPLE_H
#define ARDUINO_BLE_SENSISCAN_SAMPLE_H

#include "UnitType.h"

struct Sample {
    unsigned long timeStamp = 0;
    UnitType type = UnitType::UNDEFINED;
    float value = 0;
};

#endif // ARDUINO_BLE_SENSISCAN_SAMPLE_H
