#include "Methods.h"

double simple_iterations(double(*g)(double), double eps, double approximation) {
	double next_x = approximation, prev_x = next_x;
	unsigned iterations{};
	do {
		next_x = (*g)(prev_x);
		prev_x = next_x;
		++iterations;
	} while (std::abs(next_x - prev_x) > eps);
	return next_x;
}
