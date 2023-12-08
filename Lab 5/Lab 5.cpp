#include <iostream>
#include <memory>
#include "print_result.h"
//#include <bitset>

int array_5[constants::ARRAY_SIZE[0]]{}, array_50[constants::ARRAY_SIZE[1]]{}, array_500[constants::ARRAY_SIZE[2]]{};

int main() {
	setlocale(LC_ALL, "Russian");

	using dynamic_array = std::unique_ptr<int[]>;
	dynamic_array arr_5 { std::make_unique<int[]>(constants::ARRAY_SIZE[0])};
	auto arr_50{ std::make_unique<int[]>(constants::ARRAY_SIZE[1]) };
	auto arr_500{ std::make_unique<int[]>(constants::ARRAY_SIZE[2]) };

	fill_array(arr_5.get(), constants::ARRAY_SIZE[0], 0, 12, true);
	/*fill_array(arr_50.get(), constants::ARRAY_SIZE[1]);
	fill_array(arr_500.get(), constants::ARRAY_SIZE[2]);
	copy_array(arr_5.get(), array_5, constants::ARRAY_SIZE[0]);
	copy_array(arr_50.get(), array_50, constants::ARRAY_SIZE[1]);
	copy_array(arr_500.get(), array_500, constants::ARRAY_SIZE[2]);*/

	//copy_array<int>(arr_5.get(), array_5, size_t(constants::ARRAY_SIZE[0]));
	//copy_array_1<int, 5>(arr_5.get(), array_5);


	/*bubblesort(arr_5.get(), constants::ARRAY_SIZE[0], true);
	selection_sort(arr_5.get(), constants::ARRAY_SIZE[0], true);*/

	print_result(arr_5.get(), array_5, constants::ARRAY_SIZE[0], false);
	print_result(arr_5.get(), array_5, constants::ARRAY_SIZE[0], true);
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
Если массив объявлен статически, то есть в глобальной области видимости, в области видимости пространства имен
или в качестве статического члена класса, то он размещается в статической памяти.

Неинициализированная переменная устроена следующим образом: если она объявлена в области видимости пространства имен (глобально),
будет иметь все биты нулевыми, если локально, или создана динамически, то получит случайный набор битов.

std::is_trivial<Т>::value
*/