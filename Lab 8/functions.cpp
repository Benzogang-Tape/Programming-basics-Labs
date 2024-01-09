#include "functions.h"

std::function<unsigned(unsigned)> fact{ [](unsigned n) -> unsigned { if (n == 1 or n == 0) return 1; else return n * fact(n - 1); } };

void create_matrix(double**& matrix, const unsigned N, const unsigned M) {
	for (unsigned i{}; i < N; ++i) {
		matrix[i] = new double[M];
	}
}

double** create_matrix0(const unsigned N, const unsigned M) {
	double** matrix = new double* [N];
	for (unsigned i{}; i < N; ++i) {
		matrix[i] = new double[M];
	}
	return matrix;
}

void create_matrix1(std::unique_ptr<std::unique_ptr<double[]>[]>* matrix, const unsigned N, const unsigned M) {
	for (size_t i{}; i < N; ++i) {
		matrix->get()[i] = std::make_unique<double[]>(M);
	}
}

std::unique_ptr<std::unique_ptr<double[]>[]> create_matrix2(const unsigned N, const unsigned M) {
	std::unique_ptr<std::unique_ptr<double[]>[]> matrix{ std::make_unique<std::unique_ptr<double[]>[]>(N) };
	for (size_t i{}; i < N; ++i) {
		matrix.get()[i] = std::make_unique<double[]>(M);
	}
	return matrix;
}

void init_matrix(double matrix[constants::static_Matrix_Size][constants::static_Matrix_Size], const unsigned N) {
	for (unsigned i{}; i < N; ++i) {
		for (unsigned j{}; j < constants::static_Matrix_Size; ++j) {
			matrix[i][j] = i * 10 + j;
		}
	}
}


void init_matrix(std::unique_ptr<std::unique_ptr<double[]>[]>* matrix, const unsigned N, const unsigned M) {
	for (size_t i{}; i < N; i++) {
		for (size_t j{}; j < M; j++) {
			if (i < j) {
				if ((j - i) > 1)
					matrix->get()[i][j] = (matrix->get()[i][j - 1] / pow(j + 1, i + 1));
				else
					matrix->get()[i][j] = (pow(constants::x, i + 1) / pow(fact(j + 1), i + 1));
			}
			else if (i > j){
				if (j)
					matrix->get()[i][j] = matrix->get()[i][j - 1] / pow(i + 1, j + 1);
				else
					matrix->get()[i][j] = pow(-constants::x, i + 1) / pow(fact(j + 1), i + 1);
			}
			else {
				matrix->get()[i][j] = 1;
			}
		}
	}
}

void delete_matrix(std::unique_ptr<std::unique_ptr<double[]>[]> matrix, const unsigned N, const unsigned M) {
	for (unsigned i{}; i < N; ++i) {
		matrix[i].reset();
	}
	matrix.reset();
}

void print_matrix(const std::unique_ptr<std::unique_ptr<double[]>[]>* const matrix, const unsigned N, const unsigned M, bool fixed, const unsigned precision) {
	unsigned column_Count{ constants::max_Line_Length / (constants::integer_Part + precision) };
	std::cout << std::fixed << std::setprecision(precision);
	unsigned width{ constants::integer_Part + precision };
	if (!fixed) {
		std::cout << std::scientific;
		column_Count = constants::max_Line_Length / (constants::integer_Part + precision + 5);
		width += 5;
	}
	std::cout << std::setfill('=') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ');
	static unsigned columns_Printed{};
	unsigned current_Columns_Count{};
	while (columns_Printed < M) {
		if(columns_Printed)
			std::cout << std::setfill('-') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ');
		current_Columns_Count = [M, column_Count]() -> unsigned { if ((M - columns_Printed) / column_Count) return columns_Printed + column_Count; return columns_Printed + (M % column_Count); }();
		for (unsigned i{}; i < N; ++i) {
			for (unsigned j{ columns_Printed }; j < current_Columns_Count; ++j) {
				std::cout << std::setw(width) << matrix->get()[i][j];
			}
			std::cout << std::endl;
		}
		columns_Printed += column_Count;
	}
	std::cout << std::setfill('=') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ') << std::endl;
}

void print_matrix(const double matrix[constants::static_Matrix_Size][constants::static_Matrix_Size], const unsigned N, const unsigned M, bool fixed, const unsigned precision) {
	unsigned column_Count{ constants::max_Line_Length / (constants::integer_Part + precision) };
	std::cout << std::fixed << std::setprecision(precision);
	unsigned width{ constants::integer_Part + precision };
	if (!fixed) {
		std::cout << std::scientific;
		column_Count = constants::max_Line_Length / (constants::integer_Part + precision + 5);
		width += 5;
	}
	std::cout << std::setfill('=') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ');
	static unsigned columns_Printed{};
	unsigned current_Columns_Count{};
	while (columns_Printed < M) {
		if (columns_Printed)
			std::cout << std::setfill('-') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ');
		current_Columns_Count = [M, column_Count]() -> unsigned { if ((M - columns_Printed) / column_Count) return columns_Printed + column_Count; return columns_Printed + (M % column_Count); }();
		for (unsigned i{}; i < N; ++i) {
			for (unsigned j{ columns_Printed }; j < current_Columns_Count; ++j) {
				std::cout << std::setw(width) << matrix[i][j];
			}
			std::cout << std::endl;
		}
		columns_Printed += column_Count;
	}
	std::cout << std::setfill('=') << std::setw(constants::max_Line_Length) << ' ' << std::setfill(' ') << std::endl;
}





//Creating two-dimensional matrix function (default, with passing the pointer to the matrix to the function by reference)
/*
void create_matrix(double **&matrix, const unsigned N, const unsigned M) {
	for (unsigned i{}; i < N; ++i) {
		matrix[i] = new double[M];
	}
}

usage:
	double** matrix{new double* [constants::N]};
	create_matrix(matrix, constants::N, constants::M);

*/


//Creating two-dimensional matrix function (default, with using relocation semantics to the pointer to matrix that function returns)
/*
double** create_matrix0(const unsigned N, const unsigned M) {
	double** matrix = new double* [N];
	for (unsigned i{}; i < N; ++i) {
		matrix[i] = new double[M];
	}
	return matrix;
}

usage:
		double** matrix = std::move(create_matrix0(constants::N, constants::M));

*/


//Creating two-dimensional matrix function (with smart-pointers and passing the smart-pointer to the matrix to the function by pointer)
/*

void create_matrix1(std::unique_ptr<std::unique_ptr<double[]>[]> *matrix, const unsigned N, const unsigned M) {
	for (size_t i{}; i < N; ++i) {
		matrix->get()[i] = std::make_unique<double[]>(M);
	}
}

usage:
	auto matrix{ std::make_unique<std::unique_ptr<double[]>[]>(constants::N) };
	create_matrix1(&matrix, constants::N, constants::M);

*/


//Creating two-dimensional matrix function (with smart-pointers and using relocation semantics to the smart-pointer to matrix that function returns)
/*

std::unique_ptr<std::unique_ptr<double[]>[]> create_matrix2(const unsigned N, const unsigned M) {
	std::unique_ptr<std::unique_ptr<double[]>[]> matrix{ std::make_unique<std::unique_ptr<double[]>[]>(N) };
	for (size_t i{}; i < N; ++i) {
		matrix.get()[i] = std::make_unique<double[]>(M);
	}
	return matrix;
}

usage:
	auto matrix{ std::move(create_matrix2(constants::N, constants::M)) };
	std::unique_ptr<std::unique_ptr<double[]>[]> matrix{ std::move(create_matrix2(constants::N, constants::M)) };

*/