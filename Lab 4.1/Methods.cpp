#include "Methods.h"
#include "constants.h"

auto Methods::simple_iterations(double(*g)(double), double eps, double approximation) {
	auto next_x = approximation, prev_x = next_x;
	do {
		next_x = (*g)(prev_x);
		prev_x = next_x;
	} while (std::abs(next_x - prev_x) > eps);
	return next_x;
}
