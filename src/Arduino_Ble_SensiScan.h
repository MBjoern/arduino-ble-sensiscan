/*
 Arduino_Ble_SensiScan.h - Library for collecting sensor data via Bluetooth.
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_H
#define ARDUINO_BLE_SENSISCAN_H

#include "Arduino.h"
#include "BleClient.h"
#include "Sample.h"
#include "SampleDecoder.h"
#include <string>
#include <vector>

class SensiScan {
  public:
    explicit SensiScan(){};

    void begin();
    void getScanResults(std::vector<Sample>& samples);
    void keepAlive();

  private:
    BleClient* _bleClient;
    static void onAdvertisementReceived(std::string address, std::string name,
                                        std::string manufacturerData);
};

#endif // ARDUINO_BLE_SENSISCAN_H