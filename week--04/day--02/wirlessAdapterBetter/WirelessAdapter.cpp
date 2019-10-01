//
// Created by User on 01/10/2019.
//

#include <iostream>
#include "WirelessAdapter.h"


WirelessAdapter::WirelessAdapter(int id, int bandwidth, int usbType) : Device(id),NetworkDevice(id, bandwidth), UsbDevice(id, usbType) {}


void WirelessAdapter::info() {
    std::cout << getId() <<  _usbType <<  _bandwidth << std::endl;
}
