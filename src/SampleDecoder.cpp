/*
 SampleDecoder.cpp
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#include "SampleDecoder.h"
#include "Arduino.h"
#include "UnitType.h"
#include <map>

typedef float (*tdecodeer)(std::string, uint8_t);

struct UnitEncoding {
    UnitType unitType;
    tdecodeer converterFct;
};

struct SampleEncoding {
    uint8_t minFrameSize;
    std::map<uint8_t, UnitEncoding> unitEncoding;
};

SampleEncoding getEncoding(uint8_t sampleType) {
    switch (sampleType) {
        case 4:
            return {
                10,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}}},
            };
        case 6:
            return {
                10,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV2}}},
            };
        case 3:
            return {
                12,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::VOC, &SampleDecoder::decodeSimple}}},
            };
        case 10:
            return {
                12,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}}},
            };
        case 8:
            return {
                12,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}}},
            };
        case 12:
            return {
                14,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::PM2P5, &SampleDecoder::decodePM2p5V1}}},
            };
        case 14:
            return {
                12,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::HCHO, &SampleDecoder::decodeHCHOV1}}},
            };
        case 16:
            return {
                14,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::PM2P5, &SampleDecoder::decodePM2p5V1}}},
            };
        case 20:
            return {
                18,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {14, {UnitType::PM2P5, &SampleDecoder::decodePM2p5V1}},
                 {16, {UnitType::HCHO, &SampleDecoder::decodeHCHOV1}}},
            };
        case 22:
            return {
                14,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::NOX, &SampleDecoder::decodeSimple}}},
            };
        case 24:
            return {
                16,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::NOX, &SampleDecoder::decodeSimple}},
                 {14, {UnitType::PM2P5, &SampleDecoder::decodePMV2}}},
            };
        case 26:
            return {
                18,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {14, {UnitType::NOX, &SampleDecoder::decodeSimple}},
                 {16, {UnitType::PM2P5, &SampleDecoder::decodePMV2}}},
            };
        case 28:
            return {
                14,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                    {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                    {10, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                    {12, {UnitType::PM2P5, &SampleDecoder::decodePMV2}},
                    }
            };
        case 30:
            return {
                14,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                    {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                    {10, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                    {12, {UnitType::PM2P5, &SampleDecoder::decodePMV2}},
                }
            };
        case 31:
            return {
                18,
                {{6, {UnitType::T, &SampleDecoder::decodeTemperatureV1}},
                 {8, {UnitType::RH, &SampleDecoder::decodeHumidityV1}},
                 {10, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                 {12, {UnitType::VOC, &SampleDecoder::decodeSimple}},
                 {14, {UnitType::PM2P5, &SampleDecoder::decodePMV2}},
                 {16, {UnitType::HCHO, &SampleDecoder::decodeHumidityV2}}},
            };
        case 34:
            return {
                14,
                {{6, {UnitType::PM1P0, &SampleDecoder::decodePMV2}},
                    {8, {UnitType::PM2P5, &SampleDecoder::decodePMV2}},
                    {10, {UnitType::PM4P0, &SampleDecoder::decodePMV2}},
                    {12, {UnitType::PM10, &SampleDecoder::decodePMV2}},
                }
            };
        case 36:
            return {
                8,
                {{6, {UnitType::CO2, &SampleDecoder::decodeSimple}},
                },
            };

        default:
            return {0, {}};
    }
}

uint8_t SampleDecoder::decode(uint8_t sampleType, std::string data,
                              std::vector<Sample>& samples) {
    SampleEncoding encoding = getEncoding(sampleType);
    if (data.length() < encoding.minFrameSize) {
        return 1; // Frame too short or sampleType unknown
    }

    unsigned long timestamp = millis();
    for (const auto& item : encoding.unitEncoding) {
        Sample sample = {};
        sample.type = item.second.unitType;
        sample.value = item.second.converterFct(data, item.first);
        sample.timeStamp = timestamp;
        samples.push_back(sample);
    }

    return 0;
}

float SampleDecoder::decodeSimple(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return static_cast<float>(value);
}

float SampleDecoder::decodeTemperatureV1(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return -45.0f + ((175.0f * static_cast<float>(value)) / 65535);
}

float SampleDecoder::decodeHumidityV1(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return (100.0f * static_cast<float>(value)) / 65535;
}

float SampleDecoder::decodeHumidityV2(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return (125.0f * static_cast<float>(value)) / 65535 - 6.0f;
}

float SampleDecoder::decodePM2p5V1(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return (1000.0f * static_cast<float>(value)) / 65535;
}

float SampleDecoder::decodePMV2(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return static_cast<float>(value) / 10.0f;
}

float SampleDecoder::decodeHCHOV1(std::string data, uint8_t offset) {
    uint16_t value = getRawValue(data, offset);
    return static_cast<float>(value) / 5.0f;
}

uint16_t SampleDecoder::getRawValue(std::string data, uint8_t offset) {
    return static_cast<uint16_t>(static_cast<uint16_t>(data[offset + 1]) << 8 |
                                 static_cast<uint8_t>(data[offset]));
}
