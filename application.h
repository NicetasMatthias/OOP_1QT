#ifndef APPLICATION_H
#define APPLICATION_H

#include "polinom.h"

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
