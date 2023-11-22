#include <iostream>
#include "Solution.h"


int main() {
	setlocale(LC_ALL, "Russian");
	solution(constants::COEFFICIENTS[0], constants::EPS_1, constants::INITIAL_APPROXIMATION_1);
	solution(constants::COEFFICIENTS[0], constants::EPS_2, constants::INITIAL_APPROXIMATION_1);
	solution(constants::COEFFICIENTS[1], constants::EPS_1, constants::INITIAL_APPROXIMATION_2);
	solution(constants::COEFFICIENTS[2], constants::EPS_1, constants::INITIAL_APPROXIMATION_2);
}
