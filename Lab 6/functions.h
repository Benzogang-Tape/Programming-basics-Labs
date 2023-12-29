#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "constants.h"

using func_ref_1 = double (*)(double);
using func_ref_2 = double (*)(double, double);
using func_ref_3 = double (*) (func_ref_1, double, double, double, unsigned&);

struct I_print {			
	const char* function_name;
	double integral_sum;	
	double exact_value;		
	unsigned n;				
};

double IntRect(func_ref_1, double, double, double, unsigned&);
double IntTrap(func_ref_1, double, double, double, unsigned&);
void PrintTabl(I_print [], int);

double Sin_exact(double, double);
double X_exact(double, double);
double PowX_exact(double, double);
double Arctan_exact(double, double);
double F_sin(double);
double F_x(double);
double F_pow_x(double);
double F_arctan(double);
