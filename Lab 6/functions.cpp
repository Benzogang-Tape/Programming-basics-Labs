#include "functions.h"

using namespace constants;

double X_exact(double a, double b) { return (pow(b, 2) - pow(a, 2)) / static_cast<double>(2); }
double Sin_exact(double a, double b) { return (cos(a * static_cast<double>(22)) - cos(b * static_cast<double>(22))) / static_cast<double>(22); }
double PowX_exact(double a, double b) { return (pow(b, 5) - pow(a, 5)) / static_cast<double>(5); }
double Arctan_exact(double a, double b) { return b * atan(b) - a * atan(a) - (log(pow(b, 2) + 1) - log(pow(a, 2) + 1)) / static_cast<double>(2); }
double F_x(double x) { return x; }
double F_sin(double x) { return sin(static_cast<double>(22) * x); }
double F_pow_x(double x) { return pow(x, 4); }
double F_arctan(double x) { return atan(x); }

double IntRect(func_ref_1 f, double a, double b, double eps, unsigned& n) {
    double x{}, dx{}, prev_sum{}, new_sum{ 4 };
    do {
        x = a;
        prev_sum = new_sum;
        new_sum = 0;
        dx = (b - a) / n;
        for (; x < b; x += dx)
            new_sum += f(x + (dx / 2));
        new_sum *= dx;
        n *= 2;
    } while (abs(prev_sum - new_sum) > eps);
    n /= 2;
    return new_sum;
}

double IntTrap(func_ref_1 f, double a, double b, double eps, unsigned& n) {
    double x{}, dx{}, prev_sum{}, new_sum{ 4 };
    do {
        x = a;
        prev_sum = new_sum;
        new_sum = 0;
        dx = (b - a) / n;
        for (; x < b; x += dx)
            new_sum += (f(x) + f(x + dx)) / 2;
        new_sum *= dx;
        n *= 2;
    } while (abs(prev_sum - new_sum) > eps);
    n /= 2;
    return new_sum;
}

void PrintTabl(I_print i_prn[], int arr_size) {
    
    char* table_header[column_count]{ (char*)"Function", (char*)"Integral", (char*)"IntSum", (char*)"N " };
    unsigned size[column_count]{};
    for (unsigned i{}; i < column_count; i++) {
        size[i] = static_cast<unsigned>(strlen(table_header[i]));
    }

    // table header
    std::cout << plus << std::setfill(dash);
    for (unsigned j{}; j < column_count; j++) {
        std::cout << std::setw(column_width[j]) << plus;
    }

    std::cout << std::endl << pipe;
    for (unsigned j{}; j < column_count; j++) {
        size_t stw{ (column_width[j] - size[j]) / 2 };
        std::cout << std::setw(stw) << std::setfill(' ') << ' ' << table_header[j]
                  << std::setw(stw) << pipe;
    }
        
    std::cout << std::endl;

    // filling the table
    for (unsigned i{}; i < arr_size; i++) {
        std::cout << plus << std::fixed;
        for (unsigned j{}; j < column_count; j++) {
            std::cout << std::setfill(dash) << std::setw(column_width[j]) << plus;
        }
        std::cout << std::setfill(' ') << std::endl;

        size_t stw{ (column_width[0] - strlen(i_prn[i].function_name)) / 2 };
        std::cout << pipe << std::setw(stw) << ' ' << i_prn[i].function_name
                          << std::setw(stw) << pipe;

        std::cout << std::setw(column_width[1] - 1) << std::setprecision(10) << i_prn[i].exact_value << pipe
                  << std::setw(column_width[2] - 1) << i_prn[i].integral_sum << std::setprecision(6) << pipe
                  << std::setw(column_width[3] - 1) << i_prn[i].n << pipe << std::endl;
    }

    // table bottom
    std::cout << plus << std::setfill(dash);
    for (unsigned j{}; j < column_count; j++) {
        std::cout << std::setw(column_width[j]) << plus;
    }
    std::cout << std::setfill(' ') << "\n" << std::endl;
}
