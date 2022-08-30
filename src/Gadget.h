/*
Sample.h
Created by Pascal Sachs, 2022.
Released under BSD-3 licence
*/
#ifndef ARDUINO_BLE_SENSISCAN_GADGET_H
#define ARDUINO_BLE_SENSISCAN_GADGET_H

struct Gadget {
    std::string deviceId;  // device id of form aa:bb
    std::string name;      // gadget local name from advertisement data

    bool operator<(const Gadget& other) const
    {
        return (this->deviceId < other.deviceId);
    }
};
#endif // ARDUINO_BLE_SENSISCAN_GADGET_H
