//
// Created by User on 01/10/2019.
//

#ifndef WIRLESSADAPTERBETTER_USBDEVICE_H
#define WIRLESSADAPTERBETTER_USBDEVICE_H
#include "Device.h"

class UsbDevice : public virtual Device {
public:
    UsbDevice(int id, int usbType);

protected:
    int _usbType;
private:

};

#endif //WIRLESSADAPTERBETTER_USBDEVICE_H
