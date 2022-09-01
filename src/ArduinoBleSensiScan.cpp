/*
 ArduinoBleSensiScan.cpp - Library for collecting sensor data via Bluetooth.
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#include "ArduinoBleSensiScan.h"
#include "NimBleClient.h"

const int COMPANY_ID_FILTER = 54534;

void SensiScan::begin() {
    _bleClient = new NimBleClient();
    _bleClient->begin(this);
    _bleClient->keepAlive();
}

void SensiScan::getScanResults(
    std::map<Gadget, std::vector<Sample>>& scanResults) {
    // TODO: Copy properly
    scanResults = _sampleCache;
}

void SensiScan::keepAlive() {
    _bleClient->keepAlive();
}

void SensiScan::onAdvertisementReceived(std::string address, std::string name,
                                        std::string data) {
    uint16_t companyId = (uint16_t)data[0] << 8 | (uint8_t)data[1];
    if (companyId != COMPANY_ID_FILTER) {
        return;
    }

    uint8_t advType = (uint8_t)data[2];
    uint8_t sampleType = (uint8_t)data[3];
    std::string deviceId = getDeviceId(data);

    Gadget gadget = {deviceId, name};

    std::vector<Sample> samples;
    uint8_t error = SampleDecoder::decode(sampleType, data, samples);
    if (error) {
        return;
    }

    _sampleCache[gadget] = samples;
}

std::string SensiScan::getDeviceId(std::string data) {
    char id[6];
    sprintf(id, "%02x:%02x", (uint8_t)data[4], (uint8_t)data[5]);
    std::string deviceId(id);
    return deviceId;
}
