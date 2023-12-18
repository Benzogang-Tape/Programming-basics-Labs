#include "print_result.h"


void display_arr(int arr[], unsigned arr_size) {
	for (unsigned i{}; i < arr_size; i++) {
		std::cout << ' ' << arr[i];
	}
}

void print_result(int arr[], int aux_arr[], unsigned arr_size, bool reverse) {
	copy_array(arr, aux_arr, arr_size);
	std::cout << std::format("Количество элементов: {}. Заданный массив:", arr_size);
	display_arr(arr, arr_size);
	std::cout << '.';
	if (reverse)
		std::cout << " Сортировка по убыванию" << std::endl;
	else
		std::cout << " Сортировка по возрастанию" << std::endl;
	std::cout << std::setw(16) << "Метод		       " << 
				 std::setw(16) << "Результат           " << 
				 std::setw(16) << "Сравнений       " <<
				 std::setw(16) << "Перестановок    " << std::endl;
	copy_array(arr, aux_arr, arr_size);
	selection_sort(arr, arr_size, reverse);

	std::cout << std::setw(16) << "выбор (n)       " << std::setw(16);
	display_arr(arr, arr_size);
	std::cout << std::setw(16) << *comparisons << std::setw(16) << *swaps << std::endl;

	selection_sort(arr, arr_size, reverse);

	std::cout << std::setw(16) << "выбор (o)       " << std::setw(16);
	display_arr(arr, arr_size);
	std::cout << std::setw(16) << *comparisons << std::setw(16) << *swaps << std::endl;

	copy_array(aux_arr, arr, arr_size);
	bubble_sort(arr, arr_size, reverse);

	std::cout << std::setw(16) << "пузырёк (n)     " << std::setw(16);
	display_arr(arr, arr_size);
	std::cout << std::setw(16) << *comparisons << std::setw(16) << *swaps << std::endl;

	bubble_sort(arr, arr_size, reverse);

	std::cout << std::setw(16) << "пузырёк (o)     " << std::setw(16);
	display_arr(arr, arr_size);
	std::cout << std::setw(16) << *comparisons << std::setw(16) << *swaps << std::endl << std::endl;

	copy_array(aux_arr, arr, arr_size);
}

void print_result_bubble_sort(int arr_5[], int arr_50[], int arr_500[]) {
	std::cout << "Метод: пузырёк (n). Сортировка по возрастанию" << std::endl;
	std::cout << std::format("{:<16}{:<16}{:<16}", "N", "Сравнений", "Перестановок") << std::endl;
	bubble_sort(arr_5, constants::ARRAY_SIZE[0], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[0], *comparisons, *swaps) << std::endl;
	bubble_sort(arr_50, constants::ARRAY_SIZE[1], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[1], *comparisons, *swaps) << std::endl;
	bubble_sort(arr_500, constants::ARRAY_SIZE[2], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[2], *comparisons, *swaps) << std::endl << std::endl;
}

void print_result_selection_sort(int arr_5[], int arr_50[], int arr_500[]) {
	std::cout << "Метод: выбор (n). Сортировка по возрастанию" << std::endl;
	std::cout << std::format("{:<16}{:<16}{:<16}", "N", "Сравнений", "Перестановок") << std::endl;
	selection_sort(arr_5, constants::ARRAY_SIZE[0], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[0], *comparisons, *swaps) << std::endl;
	selection_sort(arr_50, constants::ARRAY_SIZE[1], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[1], *comparisons, *swaps) << std::endl;
	selection_sort(arr_500, constants::ARRAY_SIZE[2], false);
	std::cout << std::format("{:<16}{:<16}{:<16}", constants::ARRAY_SIZE[2], *comparisons, *swaps) << std::endl << std::endl;
}
