/*
 UnitType.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_UNITTYPE_H
#define ARDUINO_BLE_SENSISCAN_UNITTYPE_H

#include <string>

enum UnitType { UNDEFINED, T, RH, VOC, NOX, CO2, PM2P5, HCHO, PM1P0, PM4P0, PM10 };

const std::string unitTypeString[] = {"UNDEFINED", "T",   "RH",    "VOC",
                                      "NOX",       "CO2", "PM2P5", "HCHO",
                                      "PM1P0", "PM4P0", "PM10"};

#endif // ARDUINO_BLE_SENSISCAN_UNITTYPE_H
