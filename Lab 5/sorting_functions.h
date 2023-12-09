#pragma once
#include <random>
#include "constants.h"

void fill_array(int*, unsigned, int lower_limit = constants::LOWER_LIMIT, 
								int upper_limit = constants::UPPER_LIMIT, 
								bool with_negative_numbers = true);
void bubble_sort(int [], unsigned, bool reverse = false);
void selection_sort(int[], unsigned, bool reverse = false);
void copy_array(int[], int[], unsigned);
extern std::unique_ptr<unsigned> swaps, comparisons;




/*
//template<typename T, size_t static_arr_size>
//void copy_array_1(T[], T(&)[static_arr_size]);

//template<typename T>
//extern void copy_array(T[], T*, size_t);
*/