#pragma once
#include <iostream>

struct Methods {
	double eps, approximation;
	unsigned iteration_count{};
	double simple_iterations(double (*)(double));
	Methods(double, double);
};