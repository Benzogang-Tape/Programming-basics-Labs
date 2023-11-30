#include <iostream>
#include <memory>
#include <random>
#include "constants.h"
#include <bitset>


int main() {
	using dynamic_array = std::unique_ptr<int[]>;
	dynamic_array array_5 { std::make_unique<int[]>(constants::ARRAY_SIZE[0])};
	//auto array_50{ std::make_unique<int[]>(constants::ARRAY_SIZE[1]) };
	//auto array_500{ std::make_unique<int[]>(constants::ARRAY_SIZE[2]) };

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rnd_int_32(constants::LOWER_LIMIT, constants::UPPER_LIMIT);
	std::uniform_int_distribution<std::mt19937::result_type> rnd_bool(0, 1);

	//srand(time(NULL));
	constexpr int m = std::numeric_limits<int>::max();
	for (unsigned i{}; i < constants::ARRAY_SIZE[0]; i++) {
		//array_5[i] = rand();
		rnd_bool(rng) ? array_5[i] = rnd_int_32(rng) : array_5[i] = -int(rnd_int_32(rng));
	}

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