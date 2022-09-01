/*
 SampleDecoder.h
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#ifndef ARDUINO_BLE_SENSISCAN_SAMPLEDECODER_H
#define ARDUINO_BLE_SENSISCAN_SAMPLEDECODER_H

#include "Sample.h"
#include <string>
#include <vector>

namespace SampleDecoder {
uint8_t decode(uint8_t sampleType, std::string data,
               std::vector<Sample>& samples);

// Helpers
float decodeSimple(std::string data, uint8_t offset);
float decodeTemperatureV1(std::string data, uint8_t offset);
float decodeHumidityV1(std::string data, uint8_t offset);
float decodeHumidityV2(std::string data, uint8_t offset);
float decodePM2p5V1(std::string data, uint8_t offset);
float decodePMV2(std::string data, uint8_t offset);
float decodeHCHOV1(std::string data, uint8_t offset);
uint16_t getRawValue(std::string data, uint8_t offset);
}; // namespace SampleDecoder

#endif // ARDUINO_BLE_SENSISCAN_SAMPLEDECODER_H
