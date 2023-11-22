#include "Function.h"

std::string print_equation(double k) {
	if (static_cast<int>(k) == 1)
		return std::format("Equation: x - cos(x) = 0");
	else
		return std::format("Equation: x - {:.1f} * cos(x) = 0. ", k);
}

double equation(double x, double k) {
	return x - (k * std::cos(x));
}

double transformed_function(double x, double k) {
	return k * std::cos(x);
}

double derivative(double x, double k) {
	return k * std::sin(x) + 1;
}

/*
void print_equation(double k) {
	if (static_cast<int>(k) == 1)
		std::cout << "Equation: x - cos(x) = 0";
	else
		std::printf("Equation: x - %.1f * cos(x) = 0", k);
}
*/