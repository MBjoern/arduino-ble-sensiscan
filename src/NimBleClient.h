/*
 NimBleClient.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H
#define ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H

#include "BleClient.h"
#include "NimBLEDevice.h"

class NimBleClient: public BleClient, public NimBLEAdvertisedDeviceCallbacks {
  public:
    void begin(BleClientCallback* callback) override;
    void keepAlive() override;

  private:
    NimBLEScan* _bleScan;
    BleClientCallback* _callback;
    void setupAndStartBleScans();
    void onResult(NimBLEAdvertisedDevice* advertisedDevice);
};

#endif // ARDUINO_BLE_SENSISCAN_NIMBLECLIENT_H
