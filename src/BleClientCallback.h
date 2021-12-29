/*
 BleClientCallback.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_BLECLIENTCALLBACK_H
#define ARDUINO_BLE_SENSISCAN_BLECLIENTCALLBACK_H

class BleClientCallback {
  public:
    virtual ~BleClientCallback() {
    }

    virtual void onAdvertisementReceived(std::string address, std::string name,
                                         std::string data);
};

#endif // ARDUINO_BLE_SENSISCAN_BLECLIENTCALLBACK_H
