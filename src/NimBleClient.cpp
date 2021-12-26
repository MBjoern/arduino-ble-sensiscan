/*
 NimBleClient.cpp
 Created by Bjoern Muntwyler, 2021.
 Released under BSD-3 licence
 */

#include "NimBleClient.h"

void NimBleClient::begin(std::function<void(byte[], int)> callback) {
    _callback = callback;
    byte dummyArray[30];
    _callback(dummyArray, 30);
};