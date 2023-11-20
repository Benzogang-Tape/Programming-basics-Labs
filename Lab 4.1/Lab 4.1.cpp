#include <iostream>
#include "Solution.h"


int main() {
	Function function_to_solve;
	Methods solving_methods = {constants::EPS_1, constants::INITIAL_APPROXIMATION_1};
	Solution solution;
	solution.solve2(function_to_solve, solving_methods);
}
