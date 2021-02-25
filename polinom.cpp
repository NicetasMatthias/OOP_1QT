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
    number d;
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
}

number polinom::value(number x)
{
    return polinom::a*x*x+polinom::b*x+polinom::c;
}

std::string polinom::stanadart()
{
    std::stringstream ss;

    ss << std::showpos << polinom::a << "*x^2" << polinom::b << "*x" << polinom::c << std::endl;
    return ss.str();
}

std::string polinom::canon()
{
    std::stringstream ss;
    short flag;
    number rts[2];
    polinom::roots(flag,rts[0],rts[1]);

    switch (flag)
    {
    case 1:
        ss << std::showpos << polinom::a << "*(x" << -rts[0] << ")*(x" << -rts[1] << ")";
        break;
    case 2:
        ss << std::showpos << polinom::a << "*(x" << -rts[0] << ")^2";
        break;
    case 3:
        ss << "Многочлен не имеет вещественных корней";
        break;
    default:
        ss << "Неизвестная ошибка при вычислении корней";
        break;
    }
    return ss.str();
}
