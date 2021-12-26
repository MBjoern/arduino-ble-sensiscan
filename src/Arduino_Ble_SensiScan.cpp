/*
 Arduino_Ble_SensiScan.cpp - Library for collecting sensor data via Bluetooth.
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#include "Arduino_Ble_SensiScan.h"
#include "NimBleClient.h"

void SensiScan::begin() {
    _bleClient = new NimBleClient();
    _bleClient->begin(SensiScan::onAdvertisementReceived);
}

void SensiScan::getScanResults(std::vector<SensorValues>& sensorValues) {
}

void SensiScan::onAdvertisementReceived(byte advertised_data[], int size) {
    Serial.println("Data Received");
}
