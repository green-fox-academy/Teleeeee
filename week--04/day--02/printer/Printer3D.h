#ifndef PRINTER_PRINTER3D_H
#define PRINTER_PRINTER3D_H


#include "Printer.h"

class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize();


protected:

private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;



};


#endif //PRINTER_PRINTER3D_H
