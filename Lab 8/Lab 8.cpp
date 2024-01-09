#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned N{}, M{}, fixed{}, precision{};
	std::cout << "¬ведите количество строк и столбцов матрицы: ";
	std::cin >> N >> M;
	std::cout << "\n¬ведите формат отображени€ элементов матрицы:\n\n0 - дл€ вывода в экспоненциальном формате\n1 - дл€ вывода в формате с фиксированной точкой\n";
	std::cin >> fixed;
	std::cout << "¬ведите требуемую точность(количество знаков после зап€той): ";
	std::cin >> precision;
	auto matrix{ std::move(create_matrix2(N, M)) };
	init_matrix(&matrix, N, M);
	print_matrix(&matrix, N, M, static_cast<bool>(fixed), precision);
	delete_matrix(std::move(matrix), N, M);
	return 0;
}
