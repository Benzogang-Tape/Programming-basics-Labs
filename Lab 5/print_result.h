#pragma once
#include <iostream>
#include <format>
#include <iomanip>
#include <string>
#include "sorting_functions.h"

std::string display_arr(int [], unsigned);
void print_result(int [], int [], unsigned, bool);
void print_result_bubble_sort(int [], int [], int []);
void print_result_selection_sort(int [], int [], int []);