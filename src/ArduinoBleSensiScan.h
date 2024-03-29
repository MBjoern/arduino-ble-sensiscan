/*
 ArduinoBleSensiScan.h - Library for collecting sensor data via Bluetooth.
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_H
#define ARDUINO_BLE_SENSISCAN_H

#include "Arduino.h"
#include "BleClient.h"
#include "Gadget.h"
#include "Sample.h"
#include "SampleDecoder.h"
#include <map>
#include <string>
#include <vector>

class SensiScan: public BleClientCallback {
  public:
    explicit SensiScan(){};

    void begin();
    void
    getScanResults(std::map<Gadget, std::vector<Sample>>& scanResults);
    void keepAlive();

  private:
    BleClient* _bleClient;
    std::map<Gadget, std::vector<Sample>> _sampleCache;
    void onAdvertisementReceived(std::string address, std::string name,
                                 std::string manufacturerData);
    std::string getDeviceId(std::string data);
};

#endif // ARDUINO_BLE_SENSISCAN_H