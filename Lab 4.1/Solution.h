#pragma once
#include <iostream>
#include <iomanip>
#include "Methods.h"
#include "Function.h"


struct Solution {
	auto solve(double(*)(double(*)(double), double, double));
	auto solve2(Function, Methods);
};