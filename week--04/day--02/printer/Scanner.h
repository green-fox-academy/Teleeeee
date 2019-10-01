
#ifndef PRINTER_SCANNER_H
#define PRINTER_SCANNER_H


class Scanner {
public:
    Scanner(int speed);
    std::string scan();

protected:

private:
    int _speed;

};


#endif //PRINTER_SCANNER_H
