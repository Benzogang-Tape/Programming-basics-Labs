#include <iostream>
#include "Function.h"



inline double Function::equation(double x) {
	return x - (this->k) * std::cos(x);
}

inline double Function::new_function(double x) {
	return this->k * std::cos(x);
}

inline double Function::derivative(double x) {
	return this->k * std::sin(x) + 1;
}

void Function::print_equation() {
	if (static_cast<int>(this->k) == 1)
		std::cout << "Equation: x - cos(x) = 0" << std::endl;
	else
		std::printf("Equation: x - %.1f * cos(x) = 0", this->k);	
}

Function::Function() { this->k = 1.0; }

Function::Function(double k=1) {
	this->k = k;
}


/*
const auto default_precision = std::cout.precision();
	std::cout << default_precision << std::endl;
	std::cout << std::setprecision(2) << std::endl;
	const auto prec = std::cout.precision();
	std::cout << prec << std::endl;
*/