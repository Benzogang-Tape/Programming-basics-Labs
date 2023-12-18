#include "functions.h"

using namespace constants;

double X_exact(double a, double b) { return (pow(b, 2) - pow(a, 2)) / static_cast<double>(2); }
double Sin_exact(double a, double b) { return (cos(a * static_cast<double>(22)) - cos(b * static_cast<double>(22))) / static_cast<double>(22); }
double PowX_exact(double a, double b) { return (pow(b, 5) - pow(a, 5)) / static_cast<double>(5); }
double Arctan_exact(double a, double b) { return b * atan(b) - a * atan(a) - (log(pow(b, 2) + 1) - log(pow(a, 2) + 1)) / static_cast<double>(2); }
double MyX(double x) { return x; }
double MySin(double x) { return sin(static_cast<double>(22) * x); }
double MyPowX(double x) { return pow(x, 4); }
double MyArctan(double x) { return atan(x); }

double IntRect(func_ref_1 f, double a, double b, double eps, int& n) {
    double dx, newSum = 10e8, oldSum = 10, x;
    while (fabs(newSum - oldSum) > eps) {
        newSum = oldSum;
        x = a;
        dx = (b - a) / n;
        oldSum = 0;
        for (int i = 0; i < n; i++) {
            oldSum += f(x + dx / 2);
            x += dx;
        }
        oldSum *= dx;
        n *= 2;
    }
    n /= 2;
    return oldSum;
}

double IntTrap(func_ref_1 f, double a, double b, double eps, int& n) {
    double dx = (b - a) / n, oldSum = 0, newSum = 10e8;
    while (std::abs(newSum - oldSum) > eps) {
        n *= 2;
        newSum = oldSum;
        oldSum = 0;
        dx = (b - a) / n;
        for (int i = 0; i < n; ++i) {
            double x1 = a + i * dx, x2 = a + (i + 1) * dx;
            oldSum += dx * (f(x1) + f(x2)) / 2;
        }
    }
    n /= 2;
    return oldSum;
}

void PrintTabl(I_print i_prn[], int k) {
    
    

    //char* table_header[column_count] = { (char*)"Function", (char*)"Integral", (char*)"IntSum", (char*)"N " };
    std::string table_header[column_count] = { "Function", "Integral", "IntSum", "N " };
    unsigned size[column_count]{};
    for (unsigned i{}; i < column_count; i++) {
        size[i] = static_cast<unsigned>(table_header[i].length());
    }

    // table header
    std::cout << plus << std::setfill(dash);
    for (unsigned j{}; j < column_count - 1; j++) {
        std::cout << std::setw(column_width[j]) << plus;
    }
    std::cout << std::setw(column_width[column_count - 1]) << plus << std::endl;

    std::cout << pipe;
    for (unsigned j{}; j < column_count; j++) {
        std::cout << std::setw((column_width[j] - size[j]) / 2) << std::setfill(' ') << ' ' << table_header[j]
                  << std::setw((column_width[j] - size[j]) / 2) << pipe;
    }
        
    std::cout << std::endl;

    // filling the table
    for (unsigned i{}; i < k; i++) {
        std::cout << plus << std::fixed;
        for (unsigned j{}; j < column_count - 1; j++) {
            std::cout << std::setfill(dash) << std::setw(column_width[j]) << plus;
        }
        std::cout << std::setw(column_width[column_count - 1]) << plus << std::setfill(' ') << std::endl;

        std::cout << pipe << std::setw(static_cast<unsigned>((column_width[0] - i_prn[i].function_name.length()) / 2)) << ' ' << i_prn[i].function_name
                          << std::setw(static_cast<unsigned>((column_width[0] - i_prn[i].function_name.length()) / 2)) << pipe;

        std::cout << std::setw(column_width[1] - 1) << std::setprecision(10) << i_prn[i].exact_value << pipe
                  << std::setw(column_width[2] - 1) << i_prn[i].integral_sum << std::setprecision(6) << pipe
                  << std::setw(column_width[3] - 1) << i_prn[i].n << pipe << std::endl;
    }

    // table bottom
    std::cout << plus << std::setfill(dash);
    for (unsigned j{}; j < column_count - 1; j++) {
        std::cout << std::setw(column_width[j]) << plus;
    }
    std::cout << std::setw(column_width[column_count - 1]) << plus << std::setfill(' ') << std::endl;
}


/*std::cout << pipe << std::setw((int)(column_width[0] - strlen(i_prn[i].function_name)) / 2) << ' ' << i_prn[i].function_name
                          << std::setw((int)(column_width[0] - strlen(i_prn[i].function_name)) / 2) << pipe;*/