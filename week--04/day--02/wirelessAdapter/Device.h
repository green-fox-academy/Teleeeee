#ifndef WIRELESSADAPTER_DEVICE_H
#define WIRELESSADAPTER_DEVICE_H


class Device {
public:
    Device(int id);

    int getId();

protected:

private:
    int _id;
};


#endif //WIRELESSADAPTER_DEVICE_H
