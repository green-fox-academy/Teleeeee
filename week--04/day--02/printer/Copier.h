#ifndef PRINTER_COPIER_H
#define PRINTER_COPIER_H


#include <string>
#include "Printer2D.h"
#include "Scanner.h"

class Copier : public Printer2D, public Scanner {
public:
    Copier(int sizeX, int sizeY, int speed);

    std::string copy();

private:

};


#endif //PRINTER_COPIER_H
