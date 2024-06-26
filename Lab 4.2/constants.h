#pragma once

namespace constants
{
	inline constexpr unsigned METHODS_COUNT{ 3 };
	inline constexpr unsigned MAX_ITERATIONS{ 100000 };
	inline constexpr double EPS_1{ 0.000001 };
	inline constexpr double EPS_2{ 0.00000001 };
	inline constexpr double INITIAL_APPROXIMATION_1{ 0.5 };
	inline constexpr double INITIAL_APPROXIMATION_2{ 1 };
	inline constexpr double COEFFICIENTS[3] = { 1, 5, 10 };
}