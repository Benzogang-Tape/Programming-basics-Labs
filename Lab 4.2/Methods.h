#pragma once
#include <iostream>

extern unsigned iterations;
extern unsigned *iterations_count;
double simple_iterations(double, double (*)(double, double), double, double);
double half_division(double, double(*)(double, double), double, double);
