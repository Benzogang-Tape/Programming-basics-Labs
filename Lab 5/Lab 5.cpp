#include <iostream>
#include <memory>
#include "sorting_functions.h"
//#include <bitset>

int array_5[constants::ARRAY_SIZE[0]]{}, array_50[constants::ARRAY_SIZE[1]]{}, array_500[constants::ARRAY_SIZE[2]]{};

int main() {
	using dynamic_array = std::unique_ptr<int[]>;
	dynamic_array arr_5 { std::make_unique<int[]>(constants::ARRAY_SIZE[0])};
	auto arr_50{ std::make_unique<int[]>(constants::ARRAY_SIZE[1]) };
	auto arr_500{ std::make_unique<int[]>(constants::ARRAY_SIZE[2]) };

	fill_array(arr_5.get(), constants::ARRAY_SIZE[0], 14, 88);
	fill_array(arr_50.get(), constants::ARRAY_SIZE[1]);
	fill_array(arr_500.get(), constants::ARRAY_SIZE[2]);
}


/*
unsigned int un = std::numeric_limits<unsigned>::max(), un2, un3;
	int n = std::numeric_limits<int>::min(), n2 = -1;
	un2 = n;
	un3 = n2;
	std::cout << std::endl << un << "	" << un2 << "	" << un3 << std::endl;

	std::cout << std::bitset<sizeof(un2) * CHAR_BIT>(un2) << std::endl << std::bitset<sizeof(n) * CHAR_BIT>(n) << std::endl;
	std::cout << std::bitset<sizeof(n2) * CHAR_BIT>(n2) << std::endl << std::bitset<sizeof(un3) * CHAR_BIT>(un3);
*/


/*
���� ������ �������� ����������, �� ���� � ���������� ������� ���������, � ������� ��������� ������������ ����
��� � �������� ������������ ����� ������, �� �� ����������� � ����������� ������.

�������������������� ���������� �������� ��������� �������: ���� ��� ��������� � ������� ��������� ������������ ���� (���������),
����� ����� ��� ���� ��������, ���� ��������, ��� ������� �����������, �� ������� ��������� ����� �����.

std::is_trivial<�>::value
*/