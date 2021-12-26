/*
 Arduino_Ble_SensiScan.h - Library for collecting sensor data via Bluetooth.
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_H
#define ARDUINO_BLE_SENSISCAN_H

#include "Arduino.h"
#include "BleClient.h"
#include <string>
#include <vector>

class SensiScan {
  public:
    enum UnitType { T, RH, VOC, NOX, CO2, PM2P5, HCHO };
    struct SensorValues {
        std::string deviceId;
        UnitType type;
        double value;
    };

    explicit SensiScan(){};

    void begin();
    void getScanResults(std::vector<SensorValues>& sensorValues);

  private:
    BleClient* _bleClient;
    static void onAdvertisementReceived(byte advertised_data[], int size);
};

#endif // ARDUINO_BLE_SENSISCAN_H