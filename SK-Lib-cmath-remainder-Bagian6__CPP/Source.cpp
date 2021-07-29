#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cfenv>
#include <conio.h>

int main()
{
    std::cout << "remainder(+5.1, +3.0) = " << std::remainder(5.1, 3) << '\n'
        << "remainder(-5.1, +3.0) = " << std::remainder(-5.1, 3) << '\n'
        << "remainder(+5.1, -3.0) = " << std::remainder(5.1, -3) << '\n'
        << "remainder(-5.1, -3.0) = " << std::remainder(-5.1, -3) << '\n';

    // special values
    std::cout << "remainder(-0.0, 1.0) = " << std::remainder(-0.0, 1) << '\n'
        << "remainder(5.1, Inf) = " << std::remainder(5.1, INFINITY) << '\n';

    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "remainder(+5.1, 0) = " << std::remainder(5.1, 0) << '\n';
    
    if (fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID raised\n";
    }

    _getch();
    return 0;
}