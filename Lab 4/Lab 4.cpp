#include <iostream>
#include "Function.h"

int main() {
	Function<double, double> *func_to_solve = new Function<double, double>();

	auto solve = func_to_solve->equation(12.7, 13.8);
	std::cout << solve << std::endl;

	delete func_to_solve;


	/*Linker error

	Error	LNK2019	unresolved external symbol "public: __cdecl Function<double,double>::Function<double,double>(void)" (??0?$Function@NN@@QEAA@XZ) referenced in function main	Lab 4
	D:\BMSTU\Study\Course 1\Semester 1\Programming Basics\Labs\Lab 4\Lab 4.obj	1

	*/
}
