#pragma once
#include <iostream>

typedef double (*func_ref)(double, double);
extern unsigned iterations;
extern unsigned *iterations_count;
double simple_iterations(double, func_ref, double, double);
double half_division(double, func_ref, double, double);
double newton_method(double, func_ref, func_ref, double, double);
