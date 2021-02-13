#include "polinom.h"

polinom::polinom()
{
polinom::a=1;
polinom::b=0;
polinom::c=0;
polinom::x=0;
}
void polinom::set(number a,number b,number c)
{
    polinom::a=a;
    polinom::b=b;
    polinom::c=c;

}

void polinom::roots(short &flag, number &x1, number &x2)
{
    //number x1,x2,
    number d;
    //char buffer[256];

    //char flag=0;
                    /*
                    Значения flag
                    1 - два разных корня
                    2 - два одинаковых корня
                    3 - нет корней
                    */
    d=polinom::b*polinom::b-4*polinom::a*polinom::c;
    if (d>0)
    {
        x1=(-polinom::b+sqrt(d))/(2*polinom::a);
        x2=(-polinom::b-sqrt(d))/(2*polinom::a);
        flag=1;
    }
    else if (d<0)
    {
        flag = 3;
    }
    else
    {
        x1=(-polinom::b)/(2*polinom::a);
        flag=2;
    }
    /*
    switch (flag)
    {
    case 1:
        snprintf(buffer, sizeof(buffer), "x1 = %f, x2 = %f", x1, x2);
        break;
    case 2:
        snprintf(buffer, sizeof(buffer), "x1,x2 = %f", x1);
        break;
    case 3:
        snprintf(buffer, sizeof(buffer), "Многочлен не имеет вещественных корней");
        break;
    default:
        snprintf(buffer, sizeof(buffer), "Неизвестная ошибка при вычислении корней");
        break;
    }
    return buffer;
    */
}

number polinom::value(number x)
{
    return polinom::a*x*x+polinom::b*x+polinom::c;
}

std::string polinom::stanadart()
{

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%f*x^2 %+f*x %+f", polinom::a, polinom::b, polinom::c);
    return buffer;
}

std::string polinom::canon()
{
    char buffer[256];
    short flag;
    number rts[2];
    polinom::roots(flag,rts[0],rts[1]);

    switch (flag)
    {
    case 1:
        snprintf(buffer, sizeof(buffer), "%f*(x %+f)*(x %+f) ", polinom::a, -rts[0], -rts[1]);
        break;
    case 2:
        snprintf(buffer, sizeof(buffer), "%f*(x %+f)^2 ", polinom::a, -rts[0]);
        break;
    case 3:
        snprintf(buffer, sizeof(buffer), "Многочлен не имеет вещественных корней");
        break;
    default:
        snprintf(buffer, sizeof(buffer), "Неизвестная ошибка при вычислении корней");
        break;
    }
    /*
    snprintf(buffer, sizeof(buffer), polinom::roots().c_str());
    if (strcmp(buffer,"Многочлен не имеет вещественных корней")==0)
        snprintf(buffer, sizeof(buffer), polinom::stanadart().c_str());
        */
    return buffer;
}
