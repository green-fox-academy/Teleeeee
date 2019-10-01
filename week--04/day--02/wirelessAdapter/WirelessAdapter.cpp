#include "WirelessAdapter.h"


void WirelessAdapter::info(){
    std::cout << getId() << _bandwidth  << _usbType << std::endl;
}

WirelessAdapter::WirelessAdapter(int id, int usbType, int bandwidth) : UsbDevice(id, usbType),
                                                                                NetworkDevice(id, bandwidth) {}
