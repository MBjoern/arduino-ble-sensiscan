/*
 BleClient.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_BLECLIENT_H
#define ARDUINO_BLE_SENSISCAN_BLECLIENT_H

#include "Arduino.h"
#include <functional>

class BleClient {
  public:
    virtual ~BleClient() = default;

    virtual void begin(std::function<void(byte[], int)> callback) = 0;
};

#endif // ARDUINO_BLE_SENSISCAN_BLECLIENT_H
