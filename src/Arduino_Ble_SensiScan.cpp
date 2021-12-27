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
    _bleClient->keepAlive();
}

void SensiScan::getScanResults(std::vector<SensorValues>& sensorValues) {
}

void SensiScan::keepAlive() {
    _bleClient->keepAlive();
}

void SensiScan::onAdvertisementReceived(std::string address, std::string name,
                                        std::string manufacturerData) {
    Serial.printf("Gadget: %s - %s -> (%s length: %d) \n", name.c_str(),
                  address.c_str(), manufacturerData.c_str(),
                  manufacturerData.length());
}
