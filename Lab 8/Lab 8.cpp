#include "functions.h"


int main() {
	setlocale(LC_ALL, "Russian");
	unsigned N{}, M{}, fixed{}, precision{};
	std::cout << "������� ���������� ����� � �������� �������: ";
	std::cin >> N >> M;
	std::cout << "\n������� ������ ����������� ��������� �������:\n\n0 - ��� ������ � ���������������� �������\n1 - ��� ������ � ������� � ������������� ������\n" << "\x1b[4A" << "\x1b[46C";
	std::cin >> fixed;
	std::cout << "\x1b[4B" << "������� ��������� ��������(���������� ������ ����� �������): ";
	std::cin >> precision;
	std::cout << std::endl;

	auto matrix{ std::move(create_matrix(N, M)) };
	init_matrix(&matrix, N, M);
	print_matrix(&matrix, N, M, static_cast<bool>(fixed), precision);
	delete_matrix(std::move(matrix), N, M);

	double B[constants::static_Matrix_Size][constants::static_Matrix_Size]{ { } };
	double* row_pointers[constants::static_Matrix_Size]{};
	init_matrix(B, constants::static_Matrix_Size);
	get_row_pointers(B, row_pointers);
	print_matrix(row_pointers, constants::static_Matrix_Size, constants::static_Matrix_Size, true, 0);

	/*
	std::cout << B << "  " << B[0] << "  " << B[2] << std::endl;
	std::cout << B[0][0] << "  " << **B << "  " << *B[0] << std::endl;
	std::cout << *(*(B + 1)) << "  " << *B[1] << std::endl;
	std::cout << *(B[0] + 1) << "  " << *(*B + 1) << std::endl;
	std::cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << std::endl;
	*/

	return 0;
}
