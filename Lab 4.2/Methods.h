#pragma once
#include <iostream>
#include <memory>

typedef double (*func_ref)(double, double);
extern std::unique_ptr<unsigned> iterations_count;
/* Instead of the line above:
extern unsigned iterations;
extern unsigned *iterations_count;
*/
double simple_iterations(double, func_ref, double, double);
double half_division(double, func_ref, double, double);
double newton_method(double, func_ref, func_ref, double, double);
