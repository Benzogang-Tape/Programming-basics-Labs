#include "Methods.h"


double Methods::simple_iterations(double(*g)(double)){
	auto next_x = this->approximation, prev_x = next_x;
	unsigned* iterations = &(this->iteration_count);
	do {
		next_x = (*g)(prev_x);
		prev_x = next_x;
		++(*iterations);
	} while (std::abs(next_x - prev_x) > this->eps);
	return next_x;
}

Methods::Methods(double eps, double approximation) {
	this->eps = eps;
	this->approximation = approximation;
}
