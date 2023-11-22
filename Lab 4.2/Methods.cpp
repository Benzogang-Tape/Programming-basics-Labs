#include "Methods.h"
#include "constants.h"

unsigned iterations = 0;
unsigned *iterations_count = &iterations;

double simple_iterations(double k, func_ref g, double eps, double approximation) {
	double next_x = approximation, prev_x = next_x;
	*iterations_count = 0;
	do {
		prev_x = next_x;
		next_x = (*g)(prev_x, k);
		++(*iterations_count);
	} while ((std::abs(next_x - prev_x) > eps) and (*iterations_count < constants::MAX_ITERATIONS));
	return next_x;
}

double half_division(double k, func_ref f, double eps, double approximation) {
	double a = approximation, b = a + a, half{};
	*iterations_count = 0;
	do {
		half = static_cast<double>((b + a) / 2);
		(*f)(half, k) * (*f)(a, k) < 0 ? b = half : a = half;
		++(*iterations_count);
	} while ((std::abs((*f)(half, k)) > eps) and (*iterations_count < constants::MAX_ITERATIONS));
	return half;
}

double newton_method(double k, func_ref f, func_ref derivative, double eps, double approximation) {
	double next_x = approximation, prev_x = next_x;
	*iterations_count = 0;
	do {
		prev_x = next_x;
		next_x = prev_x - (*f)(prev_x, k) / (*derivative)(prev_x, k);
		++(*iterations_count);
	} while ((std::abs(next_x - prev_x) > eps) and (*iterations_count < constants::MAX_ITERATIONS));
	return next_x;
}
