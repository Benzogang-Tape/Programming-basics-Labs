#include "Methods.h"

unsigned iterations = 0;
unsigned *iterations_count = &iterations;

double simple_iterations(double k, double(*g)(double, double), double eps, double approximation) {
	double next_x = approximation, prev_x = next_x;
	*iterations_count = 0;
	do {
		prev_x = next_x;
		next_x = (*g)(prev_x, k);
		(*iterations_count)++;
	} while (std::abs(next_x - prev_x) > eps);
	return next_x;
}

double half_division(double k, double(*g)(double, double), double eps, double approximation) {
	double a = 1, b = 1.5, half{};
	*iterations_count = 0;
	do {
		half = static_cast<double>((b + a) / 2);
		(*g)(half, k) * (*g)(a, k) < 0 ? b = half : a = half;
		++(*iterations_count);
	} while (std::abs((*g)(half, k)) > eps);
	return half;
}