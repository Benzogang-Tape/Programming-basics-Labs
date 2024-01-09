#pragma once

#include <iostream>
#include<functional>
#include<memory>
#include<iomanip>
#include"constants.h"

void create_matrix(double**&, const unsigned, const unsigned);
double** create_matrix0(const unsigned, const unsigned);
void create_matrix1(std::unique_ptr<std::unique_ptr<double[]>[]>*, const unsigned, const unsigned);
std::unique_ptr<std::unique_ptr<double[]>[]> create_matrix2(const unsigned, const unsigned);

void init_matrix(double**, const unsigned, const unsigned);
void init_matrix(std::unique_ptr<std::unique_ptr<double[]>[]>*, const unsigned, const unsigned);

void delete_matrix(std::unique_ptr<std::unique_ptr<double[]>[]>, const unsigned, const unsigned);

void print_matrix(const std::unique_ptr<std::unique_ptr<double[]>[]>* const, const unsigned, const unsigned, bool fixed=true, const unsigned precision = constants::default_precision);