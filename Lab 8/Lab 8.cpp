#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned N{}, M{}, fixed{}, precision{};
	std::cout << "������� ���������� ����� � �������� �������: ";
	std::cin >> N >> M;
	std::cout << "\n������� ������ ����������� ��������� �������:\n\n0 - ��� ������ � ���������������� �������\n1 - ��� ������ � ������� � ������������� ������\n";
	std::cin >> fixed;
	std::cout << "������� ��������� ��������(���������� ������ ����� �������): ";
	std::cin >> precision;
	auto matrix{ std::move(create_matrix2(N, M)) };
	init_matrix(&matrix, N, M);
	print_matrix(&matrix, N, M, static_cast<bool>(fixed), precision);
	delete_matrix(std::move(matrix), N, M);
	return 0;
}
