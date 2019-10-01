#ifndef PRINTER_PRINTER2D_H
#define PRINTER_PRINTER2D_H


#include "Printer.h"

class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;

protected:

private:
    int _sizeX;
    int _sizeY;
};


#endif //PRINTER_PRINTER2D_H
