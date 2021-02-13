#include "application.h"
#include <iostream>
#define DBG 0

application::application()
{
    application::var=0;
}

void application::menu()
{
    short flag;
    number tmp[3];
    while (application::var!=6)
    {
        std::cout   << "Выберите желаемое действие путем ввода числа:" << std::endl
                    << "1 - Ввести коэффициенты a, b, c" << std::endl
                    << "2 - Рассчитать корни полинома" << std::endl
                    << "3 - Рассчитать значение полинома при указанном x" << std::endl
                    << "4 - Вывести полином в стандартной форме" << std::endl
                    << "5 - Вывести полином в канонической форме" << std::endl
                    << "6 - Закончить работу с приложением" << std::endl
                    << ">>";
        std::cin >> application::var;
        if (DBG) std::cout << "var = " << application::var << std::endl;
        switch (application::var)
        {
        case 1:
            if (DBG) std::cout << 1 << std::endl;
            std::cout << "a = ";
            std::cin >> tmp[0];
            std::cout << "b = ";
            std::cin >> tmp[1];
            std::cout << "c = ";
            std::cin >> tmp[2];
            application::p.set(tmp[0],tmp[1],tmp[2]);
            break;
        case 2:
            if (DBG) std::cout << 2 << std::endl;
            //std::cout << application::p.roots() << std::endl;
            application::p.roots(flag, tmp[0],tmp[1]);
            switch (flag)
            {
            case 1:
                std::cout << "x1 = " << tmp[0] << std::endl << "x2 = " << tmp[1] << std::endl;
                break;
            case 2:
                std::cout << "x1,x2 = " << tmp[0] << std::endl;
                break;
            case 3:
                std::cout << "Многочлен не имеет вещественных корней" << std::endl;
                break;
            default:
                std::cout << "Неизвестная ошибка при вычислении корней" << std::endl;
                break;
            }

            break;
        case 3:
            if (DBG) std::cout << 3 << std::endl;
            std::cout << "x = ";
            std::cin >> tmp[0];
            std::cout << "p(" << tmp[0] << ") = " << application::p.value(tmp[0]) << std::endl;
            break;
        case 4:
            if (DBG) std::cout << 4 << std::endl;
            std::cout << application::p.stanadart() << std::endl;
            break;
        case 5:
            if (DBG) std::cout << 5 << std::endl;
            std::cout << application::p.canon() << std::endl;
            break;
        case 6:
            if (DBG) std::cout << 6 << std::endl;
            std::cout << "Завершение работы" << std::endl;
            break;
        default:
            if (DBG) std::cout << 0 << " "<< application::var << std::endl;
            break;
        }
        std::cout   << std::endl << std::endl;
    }
}
