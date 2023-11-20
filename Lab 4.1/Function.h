#pragma once
#include <cmath>

struct Function {
	double k;
	inline double equation(double x);
	inline double new_function(double x);
	inline double derivative(double x);
	void print_equation();
	Function();
	Function(double);
	//double(*functions[3])(double) = { new_function, new_function, new_function };
};
