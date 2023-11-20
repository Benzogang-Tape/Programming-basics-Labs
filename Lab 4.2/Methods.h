#pragma once
#include <iostream>

inline unsigned iterations = 0;
inline unsigned *iterations_count = &iterations;
double simple_iterations(double, double (*)(double, double), double, double);
double half_division(double, double(*)(double, double), double, double);
