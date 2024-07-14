#pragma once

namespace constants {
    inline const char pipe{ '|' };
    inline const char dash{ '-' };
    inline const char plus{ '+' };
    inline const int eps[5] = { -2, -3, -4 , -5, -6 };
    inline const unsigned functions_count{ 4 };
    inline const unsigned column_count{ 4 };
    inline const unsigned column_width[column_count]{ 12, 18, 18, 10 };
    inline const char functions_init[functions_count][12] = { "y=x ", "y=sin(22x)", "y=x^4 ", "y=arctg(x)" };
    inline const char method_name[2][31] = { "прямоугольников", "трапеций" };
}