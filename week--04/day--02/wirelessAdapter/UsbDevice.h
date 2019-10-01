#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H
#include "Device.h"

class UsbDevice : public virtual Device {
public:
    UsbDevice(int id, int usbType);

protected:

private:
    int _usbType;
};


#endif //WIRELESSADAPTER_USBDEVICE_H
