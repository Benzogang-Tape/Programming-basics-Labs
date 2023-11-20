#include "Solution.h"

void print_equation(double k) {
	if (static_cast<int>(k) == 1)
		std::cout << "Equation: x - cos(x) = 0";
	else
		std::printf("Equation: x - %.1f * cos(x) = 0", k);
}

inline double transformed_function(double x, double k) {
	return k * std::cos(x);
}

inline double derivative(double x, double k) {
	return k * std::sin(x) + 1;
}