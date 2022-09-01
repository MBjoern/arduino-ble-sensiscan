#include <Arduino.h>
#include "ArduinoBleSensiScan.h"

SensiScan sensiScan = SensiScan();

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    sensiScan.begin();
}

void printScanResults(std::map<Gadget, std::vector<Sample>> &scanResults) {
    Serial.println("New Scan Results:");
    for (const auto& item : scanResults) {
        Gadget gadget = item.first;
        Serial.printf(" - %s Gadget with Id: %s \n", gadget.name.c_str(), gadget.deviceId.c_str());
        for (int i = 0; i < item.second.size(); i++) {
            Serial.printf("  - %s -> %f \n", unitTypeString[item.second[i].type].c_str(), item.second[i].value);
        }
    }
}

void loop() {
    std::map<Gadget, std::vector<Sample>> scanResults;
    delay(1000);

    sensiScan.getScanResults(scanResults);

    printScanResults(scanResults);
}