#include <iostream>
#include "Function.h"


int main() {
	Function *function_to_solve = new Function(5);
	function_to_solve->print_equation();
	delete function_to_solve;
}
