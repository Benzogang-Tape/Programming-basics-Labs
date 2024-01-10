#pragma once

#include <iostream>
#include<functional>
#include<memory>
#include<iomanip>
#include"constants.h"


std::unique_ptr<std::unique_ptr<double[]>[]> create_matrix(const unsigned, const unsigned);
void init_matrix(double [constants::static_Matrix_Size][constants::static_Matrix_Size], const unsigned);
void init_matrix(std::unique_ptr<std::unique_ptr<double[]>[]>*, const unsigned, const unsigned);
void print_matrix(const std::unique_ptr<std::unique_ptr<double[]>[]>* const, const unsigned, const unsigned, bool fixed=true, const unsigned precision = constants::default_precision);
void print_matrix(const double* const [], const unsigned, const unsigned, const bool fixed = true, const unsigned precision = constants::default_precision);
void delete_matrix(std::unique_ptr<std::unique_ptr<double[]>[]>, const unsigned, const unsigned);
void get_row_pointers(double[][constants::static_Matrix_Size], double* [constants::static_Matrix_Size]);
