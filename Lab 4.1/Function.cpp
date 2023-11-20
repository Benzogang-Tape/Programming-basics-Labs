#include <iostream>
#include "Function.h"



inline auto Function::equation(double x) -> decltype(x - this->k * std::cos(x)) {
	return x - (this->k) * std::cos(x);
}

inline auto Function::new_function(double x) -> decltype(this -> k* std::cos(x)) {
	return this->k * std::cos(x);
}

inline auto Function::derivative(double x) -> decltype(this -> k* std::sin(x) + 1) {
	return this->k * std::sin(x) + 1;
}

void Function::print_equation() {
	if (static_cast<int>(this->k) == 1)
		std::cout << "Equation: x - cos(x) = 0\n" << std::endl;
	else
		std::printf("Equation: x - %.1f * cos(x) = 0\n", this->k);	
}

Function::Function(double k) {
	this->k = k;
}


/*
const auto default_precision = std::cout.precision();
	std::cout << default_precision << std::endl;
	std::cout << std::setprecision(2) << std::endl;
	const auto prec = std::cout.precision();
	std::cout << prec << std::endl;
*/