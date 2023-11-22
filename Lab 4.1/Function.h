#pragma once
#include <cmath>

struct Function {
	double k;
	inline auto equation(double x) -> decltype(x - this->k * std::cos(x));
	inline auto new_function(double x) -> decltype(this->k * std::cos(x));
	inline auto derivative(double x) -> decltype(this->k* std::sin(x) + 1);
	static void print_equation();
	Function(double k);

/*
	inline double equation(double x);
	inline double new_function(double);
	inline double derivative(double x);
	void print_equation();
	Function();
	Function(double);
	//double(*functions[3])(double) = { new_function, new_function, new_function };
*/
};
