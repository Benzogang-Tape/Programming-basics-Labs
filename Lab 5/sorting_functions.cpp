#include "sorting_functions.h"


std::unique_ptr<unsigned> swaps{ std::make_unique<unsigned>(0) }, comparisons{ std::make_unique<unsigned>(0) };

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
void bubble_sort(int arr[], unsigned arr_size, bool reverse) {
	*swaps = 0;
	*comparisons = 0;
	if (reverse) {
		for (unsigned i{}; i < arr_size - 1; i++) {
			unsigned current_swaps{};
			for (unsigned j{}; j < arr_size - i - 1; j++) {
				if (arr[j + 1] > arr[j]) {
					std::swap(arr[j], arr[j + 1]);
					(*swaps)++;
					current_swaps++;
				}
				(*comparisons)++;
			}
			if (current_swaps == 0)
				break;
		}
	}
	else {
		for (unsigned i{}; i < arr_size - 1; i++) {
			unsigned current_swaps{};
			for (unsigned j{}; j < arr_size - i - 1; j++) {
				if (arr[j + 1] < arr[j]) {
					std::swap(arr[j], arr[j + 1]);
					(*swaps)++;
					current_swaps++;
				}
				(*comparisons)++;
			}
			if (current_swaps == 0)
				break;
		}
	}
}


void selection_sort(int arr[], unsigned arr_size, bool reverse) {
	*swaps = 0;
	*comparisons = 0;
	if (reverse) {
		for (unsigned i{}; i < arr_size - 1; i++) {
			unsigned max_index{ i };
			for (unsigned j = i + 1; j < arr_size; j++) {
				if (arr[j] >= arr[max_index]) {
					max_index = j;
				}
				(*comparisons)++;
			}
			if ((i != max_index) and (arr[i] != arr[max_index])) {
				std::swap(arr[i], arr[max_index]);
				(*swaps)++;
			}
		}
	}
	else {
		for (unsigned i{}; i < arr_size - 1; i++) {
			unsigned min_index{ i };
			for (unsigned j = i + 1; j < arr_size; j++) {
				if (arr[j] <= arr[min_index]) {
					min_index = j;
				}
				(*comparisons)++;
			}
			if ((i != min_index) and (arr[i] != arr[min_index])) {
				std::swap(arr[i], arr[min_index]);
				(*swaps)++;
			}	
		}
	}	
}


void copy_array(int arr_to_be_copied[], int arr_where_to_copy[], unsigned arr_size) {
	for (unsigned i{}; i < arr_size; i++)
		arr_where_to_copy[i] = arr_to_be_copied[i];
}


/*
//
//template<typename T, size_t static_arr_size>
//void copy_array_1(T arr[], T(&static_arr)[static_arr_size]) {
//	for (unsigned i{}; i < static_arr_size; i++)
//		static_arr[i] = arr[i];
//}

//
//template<typename T>
//void copy_array(T arr[], T *static_arr, size_t array_size) {
//	for (unsigned i{}; i < array_size; i++)
//		*(static_arr + i) = arr[i];
//}
*/