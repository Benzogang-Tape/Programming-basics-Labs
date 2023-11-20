#include "Solution.h"

void solution(double k, double eps, double approximation) {
	std::cout << "Calculation error: " << std::fixed << eps << std::endl;
	std::cout << std::setw(16) << "Method ¹" << std::setw(16) << "x" << std::setw(16) << "N" << std::endl;
	for (const auto& meth : methods) {
		std::cout << std::setw(16) << "1" << std::setw(16) << meth(k, transformed_function, eps, approximation) << (*iterations_count) << std::endl;
		std::cout << "test" << std::endl;
	}
}

/*
for (const auto& meth : methods) {
		std::cout << std::setw(16) << "1" << std::setw(16) << meth(k, functions[0], eps, approximation) << *iterations_count << std::endl;
	}
*/