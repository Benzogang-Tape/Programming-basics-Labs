#pragma once
#include <iostream>
#include <iomanip>
#include "constants.h"
#include "Methods.h"
#include "Function.h"


struct Solution {
	//auto solve(double(*)(double(*)(double), double, double));
	/*double(*functions[3])(double) = { Function::new_function, Function::new_function, Function::new_function };
	double(*methods[3])(double) = { Methods::simple_iterations, Methods::simple_iterations, Methods::simple_iterations };*/
	double(*func)(double) = Function::new_function;
	void solve2(Function, Methods);
};