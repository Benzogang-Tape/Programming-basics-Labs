#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	using namespace constants;

	double a, b;
	unsigned n{ 1 };
	const func_ref_1 functions[4]{ F_x, F_sin, F_pow_x, F_arctan };
	const func_ref_2 functions_exact[4]{ X_exact, Sin_exact, PowX_exact, Arctan_exact };
	const func_ref_3 IntСalculationFuncs[2]	{ IntRect, IntTrap };
	I_print i_pr[4] = { {} };

	std::cout << "Введите нижнюю границу интегрирования: ";
	std::cin >> a;
	std::cout << "Введите верхнюю границу интегрирования: ";
	std::cin >> b;
	
	for (unsigned j{}; j < 4; j++) {
		i_pr[j].function_name = functions_init[j];
		i_pr[j].exact_value = functions_exact[j](a, b);
	}
	for (unsigned k{}; k < 2; k++) {
		std::cout << std::setfill('_') << "\n" << std::setw(25) << "Метод " << method_name[k] << std::setw(20) << ' ' << std::endl;
		for (unsigned i{}; i < 5; i++)
		{
			std::cout << "\neps = " << std::setprecision(abs(eps[i])) << pow(10, eps[i]) << std::endl;
			for (unsigned j{}; j < 4; j++)
			{
				n = 1;
				i_pr[j].integral_sum = IntСalculationFuncs[k](functions[j], a, b, pow(10, eps[i]), n);
				i_pr[j].n = n;
			}
			PrintTabl(i_pr, functions_count);
		}
	}
}
