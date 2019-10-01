//
// Created by User on 01/10/2019.
//

#ifndef WIRLESSADAPTERBETTER_NETWORKDEVICE_H
#define WIRLESSADAPTERBETTER_NETWORKDEVICE_H
#include "Device.h"

class NetworkDevice: public virtual Device {
public:
    NetworkDevice(int id, int bandwidth);

protected:
    int _bandwidth;
private:

};


#endif //WIRLESSADAPTERBETTER_NETWORKDEVICE_H
