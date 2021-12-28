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

void loop() {
    std::vector<Sample> samples;
    delay(1000);

    sensiScan.getScanResults(samples);
}
