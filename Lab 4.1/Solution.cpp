#include "Solution.h"

auto Solution::solve(double(*method)(double(*)(double), double, double)) {
	Function::print_equation();
}
//auto Solution::solve(double(*method)(double(*)(double), double, double)) {
//	
//}

auto Solution::solve2(Function F, Methods M) {
	Function::print_equation();
/*void Solution::solve2(Function F, Methods M) {
	F.print_equation();
	std::cout << "Calculation error: " << M.eps << std::endl;
	std::cout << std::setw(16) << "Method N¹" << std::setw(16) << "x" << std::setw(16) << "N" << std::endl;
	for (unsigned i{}; i < 3; ++i) {
		std::cout << std::setw(16) << i << std::setw(16) << M.simple_iterations(F.new_function(12.3)) << std::setw(16) << M.iteration_count << std::endl;
	}*/
}
