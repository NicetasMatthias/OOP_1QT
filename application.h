#ifndef APPLICATION_H
#define APPLICATION_H

#include "polinom.h"
#include <iostream>

class application
{
private:
    polinom p;
    short var;

public:
    application();
    void menu();
};

#endif // APPLICATION_H
