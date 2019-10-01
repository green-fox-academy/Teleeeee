//
// Created by User on 01/10/2019.
//

#ifndef WIRLESSADAPTERBETTER_WIRELESSADAPTER_H
#define WIRLESSADAPTERBETTER_WIRELESSADAPTER_H


#include "NetworkDevice.h"
#include "UsbDevice.h"

class WirelessAdapter: public NetworkDevice, public UsbDevice {
public:
    WirelessAdapter( int id, int bandwidth, int usbType);

    void info();

private:


};


#endif //WIRLESSADAPTERBETTER_WIRELESSADAPTER_H
