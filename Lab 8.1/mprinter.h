#pragma once

#include <iostream>
#include<functional>
#include<iomanip>
#include"constants.h"

void create_matrix(double**&, const unsigned, const unsigned);
void init_dymanic_matrix(double**, const unsigned, const unsigned);
void init_static_matrix(double [][constants::static_Matrix_Size], const unsigned);
void print_matrix(const double* const [], const unsigned, const unsigned, const bool fixed = true, const unsigned precision = constants::default_precision);
void delete_matrix(double**&, const unsigned, const unsigned);
void get_row_pointers(double[][constants::static_Matrix_Size], double* [constants::static_Matrix_Size]);
