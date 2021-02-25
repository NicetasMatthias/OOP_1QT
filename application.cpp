#include "application.h"
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
        std :: cout << "Select the desired action by entering a number:" << std :: endl
                    << "1 - Enter coefficients a, b, c" << std :: endl
                    << "2 - Calculate the roots of the polynomial" << std :: endl
                    << "3 - Calculate the value of the polynomial at the specified x" << std :: endl
                    << "4 - Print the polynomial in standard form" << std :: endl
                    << "5 - Print the polynomial in canonical form" << std :: endl
                    << "6 - End application" << std :: endl
                    << ">>";
        std::cin >> application::var;
        if (DBG) std::cout << "var = " << application::var << std::endl;
        switch (application::var)
        {
        case 1:
            if (DBG) std::cout << 1 << std::endl;
            std::cout << "a!=0\n";
            do
            {
                std::cout << "a = ";
                std::cin >> tmp[0];
            }
            while(tmp[0]==0);
            std::cout << "b = ";
            std::cin >> tmp[1];
            std::cout << "c = ";
            std::cin >> tmp[2];
            application::p.set(tmp[0],tmp[1],tmp[2]);
            break;
        case 2:
            if (DBG) std::cout << 2 << std::endl;
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
                std :: cout << "The polynomial has no real roots" << std :: endl;
                break;
            case 4:
                std :: cout << "Polynomial roots are not integer" << std :: endl;
                break;
            case 5:
                std::cout << "x1 = " << tmp[0] << ",x2 not integer";
                break;
            default:
                std::cout << "Unknown error while calculating roots" << std::endl;
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
            std::cout << application::p.standart() << std::endl;
            break;
        case 5:
            if (DBG) std::cout << 5 << std::endl;
            std::cout << application::p.canon() << std::endl;
            break;
        case 6:
            if (DBG) std::cout << 6 << std::endl;
            break;
        default:
            if (DBG) std::cout << 0 << " "<< application::var << std::endl;
            break;
        }
        std::cout   << std::endl << std::endl;
    }
    std::cout << "Completion of work" << std::endl;
}
