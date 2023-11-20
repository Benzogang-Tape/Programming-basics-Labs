#pragma once
#include <cmath>

struct Function {
	double k;
	inline auto equation(double x) -> decltype(x - this->k * std::cos(x));
	inline auto new_function(double x) -> decltype(this->k * std::cos(x));
	inline auto derivative(double x) -> decltype(this->k* std::sin(x) + 1);
	void print_equation();
	Function(double k);
};
