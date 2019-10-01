#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H
#include "NetworkDevice.h"
#include "UsbDevice.h"


class WirelessAdapter: public UsbDevice,  public NetworkDevice {
public:
    WirelessAdapter(int id, int usbType, int bandwidth);

    void info();

protected:

private:


};


#endif //WIRELESSADAPTER_WIRELESSADAPTER_H
