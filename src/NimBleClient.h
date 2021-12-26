/*
 NimBleClient.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H
#define ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H

#include "BleClient.h"

class NimBleClient : public BleClient {
  public:
    void begin(std::function<void(byte[], int)> callback) override;

  private:
    std::function<void(byte[], int)> _callback;
};

#endif // ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H
