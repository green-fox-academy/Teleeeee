//
// Created by User on 01/10/2019.
//

#ifndef WIRLESSADAPTERBETTER_DEVICE_H
#define WIRLESSADAPTERBETTER_DEVICE_H


class Device {
public:
    explicit Device(int id);

    int getId();

protected:
    int _id;
private:

};


#endif //WIRLESSADAPTERBETTER_DEVICE_H
