#ifndef POLINOM_H
#define POLINOM_H

#include <number.h>
#include <string>
#include <string.h>
#include <cmath>

class polinom
{
private:
    number a;
    number b;
    number c;
    number x;
public:
    polinom();
    void set(number a,number b,number c);
    void roots(short &flag, number &x1, number &x2);
    number value(number x);
    std::string stanadart();
    std::string canon();
};

#endif // POLINOM_H