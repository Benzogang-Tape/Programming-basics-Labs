#include "sorting_functions.h"


std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> rnd_bool(0, 0);

void fill_array(int* array, unsigned array_size, int lower_limit, int upper_limit, bool with_negative_numbers) {
	std::uniform_int_distribution<std::mt19937::result_type> rnd_int_32(lower_limit, upper_limit);
	if (with_negative_numbers) {
		rnd_bool.reset();
		std::uniform_int_distribution<std::mt19937::result_type> rnd_bool_1(0, 1);
		rnd_bool = rnd_bool_1;
	}
	//srand(time(NULL));
	for (unsigned i{}; i < array_size; i++) {
		//array_5[i] = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
		(!rnd_bool(rng)) ? array[i] = rnd_int_32(rng) : array[i] = -int(rnd_int_32(rng));
	}
}
