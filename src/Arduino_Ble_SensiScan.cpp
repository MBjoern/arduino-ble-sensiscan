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

void SensiScan::getScanResults(std::vector<Sample>& samples) {
}

void SensiScan::keepAlive() {
    _bleClient->keepAlive();
}

void SensiScan::onAdvertisementReceived(std::string address, std::string name,
                                        std::string data) {
    Serial.printf("Gadget: %s - %s -> (%s length: %d) \n", name.c_str(),
                  address.c_str(), data.c_str(), data.length());

    uint16_t companyId = (uint16_t)data[0] << 8 | (uint8_t)data[1];
    if (companyId != 54534) {
        Serial.println(" => Not a Sensirion Gadget -> Discard");
        return;
    }

    uint8_t advType = (uint8_t)data[2];
    uint8_t sampleType = (uint8_t)data[3];
    char id[5];
    sprintf(id, "%02x:%02x", (uint8_t)data[4], (uint8_t)data[5]);
    std::string deviceId(id);
    Serial.printf(" => (%d) [%d|%d] :: DeviceId: %s \n", companyId, advType,
                  sampleType, deviceId.c_str());

    std::vector<Sample> samples;
    uint8_t error = SampleDecoder::decode(sampleType, data, samples);
    for (int i = 0; i < samples.size(); i++) {
        Serial.printf("  - %d -> %f \n", samples[i].type, samples[i].value);
    }
}
