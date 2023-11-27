#include "Solution.h"

void solution(double k, double eps, double approximation) {
	std::cout << print_equation(k) << std::format("Calculation error: {:.8g}", eps) << std::endl;
	std::cout << std::format("{:<16}{:<16}{}", "Method ¹", "x", "N") << std::endl;
	unsigned iter = 1;
	for (const auto& meth : methods) {
		std::cout << std::format("{:<16}{:<16.7f}{}", iter, meth(k, functions[iter - 1], eps, approximation), (*iterations_count)) << std::endl;
		iter++;
	}
	std::cout << std::format("{:<16}{:<16.7f}{}", iter, newton_method(k, functions[1], functions[2], eps, approximation), (*iterations_count)) << std::endl << std::endl;
}



/*
std::cout << print_equation(k) << "Calculation error: " << std::fixed << eps << std::endl;
std::cout << std::setw(16) << "Method ¹" << std::setw(16) << "x" << std::setw(16) << "N" << std::endl;
for (const auto& meth : methods) {
		std::cout << std::setw(16) << iter << std::setw(16) << meth(k, functions[iter - 1], eps, approximation) << std::setw(16) << (*iterations_count) << std::endl;
	}
*/