#include "print_result.h"


std::string display_arr(int arr[], unsigned arr_size) {
	std::string result = "";
	for (unsigned i{}; i < arr_size; i++)
		result = result + " " + std::to_string(arr[i]);
	return result;
}

void print_result(int arr[], int aux_arr[], unsigned arr_size, bool reverse) {
	copy_array(arr, aux_arr, arr_size);
	std::cout << std::format("���������� ���������: {}. �������� ������:{}", arr_size, display_arr(arr, arr_size));
	std::cout << '.';
	if (reverse)
		std::cout << " ���������� �� ��������" << std::endl;
	else
		std::cout << " ���������� �� �����������" << std::endl;
	std::cout << std::setw(16) << "�����		       " << 
				 std::setw(16) << "���������           " << 
				 std::setw(16) << "���������       " <<
				 std::setw(16) << "������������    " << std::endl;
	copy_array(arr, aux_arr, arr_size);
	selection_sort(arr, arr_size, reverse);
	std::cout << std::setw(16) << "��������� (n)   " <<
				 std::setw(16) << display_arr(arr, arr_size) <<
				 std::setw(16) << *comparisons <<
				 std::setw(16) << *swaps << std::endl;
	selection_sort(arr, arr_size, reverse);
	std::cout << std::setw(16) << "��������� (o)   " <<
		std::setw(16) << display_arr(arr, arr_size) <<
		std::setw(16) << *comparisons <<
		std::setw(16) << *swaps << std::endl;
	copy_array(aux_arr, arr, arr_size);
	bubblesort(arr, arr_size, reverse);
	std::cout << std::setw(16) << "������ (n)     " <<
		std::setw(16) << display_arr(arr, arr_size) <<
		std::setw(16) << *comparisons <<
		std::setw(16) << *swaps << std::endl;
	bubblesort(arr, arr_size, reverse);
	std::cout << std::setw(16) << "������ (o)     " <<
		std::setw(16) << display_arr(arr, arr_size) <<
		std::setw(16) << *comparisons <<
		std::setw(16) << *swaps << std::endl << std::endl;
}
