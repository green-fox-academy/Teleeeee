#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Scanner.h"
#include "Copier.h"

int main( int argc, char* args[] )
{

    std::vector<Printer* > holdPrinter;

    Printer2D first2D(2, 2);
    Printer2D second2D(4, 4);
    Printer2D third2D(6, 6);
    Printer3D first3D(2, 2, 2);
    Printer3D second3D(4, 4, 4);

    holdPrinter.push_back(&first2D);
    holdPrinter.push_back(&second2D);
    holdPrinter.push_back(&third2D);
    holdPrinter.push_back(&first3D);
    holdPrinter.push_back(&second3D);

    for (int i = 0; i < holdPrinter.size() ; ++i) {
        holdPrinter[i]->print();
    }

    std::vector<Scanner*> holdScanners;

    Scanner firstScanner(2 );
    Scanner secondScanner(4 );
    Copier firstCopier(2,2,2);
    Copier sceondCopier(4,4,4);

    holdScanners.push_back(&firstScanner);
    holdScanners.push_back(&secondScanner);
    holdScanners.push_back(&firstCopier);
    holdScanners.push_back(&sceondCopier);

    for (int i = 0; i < holdScanners.size() ; ++i) {
        holdScanners[i]->scan();
    }

    firstCopier.copy();






    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.
}