#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	using namespace constants;
	std::cout << "Введите a и b" << std::endl;
	double a, b;
	std::cin >> a >> b;
	int n = 2;
	I_print i_pr[4] = { {} };
	std::string functions_init[4] = { "y=x ", "y=sin(22x)", "y=x^4 ", "y=arctg(x)" };
	std::string method_name[2] = { "Метод прямоугольников", "Метод трапеций" };
	func_ref_1 functions[4]{ MyX, MySin, MyPowX, MyArctan };
	func_ref_2 functions_exact[4]{ X_exact, Sin_exact, PowX_exact, Arctan_exact };
	func_ref_3 IntСalculation[2]{ IntRect, IntTrap };
	for (unsigned j{}; j < 4; j++) {
		n = 1;
		i_pr[j].function_name = functions_init[j];
		i_pr[j].exact_value = functions_exact[j](a, b);
	}
	for (unsigned k{}; k < 2; k++) {
		std::cout << "From " << a << " to " << b << ", " << method_name[k] << std::endl;
		for (unsigned i{}; i < 5; i++)
		{
			std::cout << "-----------------------Eps: " << std::setprecision(abs(eps[i])) << pow(10, eps[i]) << "-----------------------" << std::endl;
			for (unsigned j{}; j < 4; j++)
			{
				n = 1;
				i_pr[j].integral_sum = IntСalculation[k](functions[j], a, b, pow(10, eps[i]), n);
				i_pr[j].n = n;
			}
			PrintTabl(i_pr, 4);
		}
	}
}
