#include <Arduino.h>
#include "Arduino_Ble_SensiScan.h"
#include <list>
#include <vector>

SensiScan sensiScan = SensiScan();

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    sensiScan.begin();
}

void printScanResults(std::vector<SensiScan::SensorValues>& scanResults) {
    Serial.print("New ScanResults: Count = ");
    Serial.println(scanResults.size());
    for (int i = 0; i < scanResults.size(); i++) {
        Serial.print(" - Scan Result: ");
        Serial.print(i);
        Serial.print(" -> DeviceId = ");
        Serial.println(scanResults[i].deviceId.c_str());
    }
}

void loop() {
    std::vector<SensiScan::SensorValues> scanResults;
    delay(1000);

    sensiScan.getScanResults(scanResults);
    printScanResults(scanResults);
}
