#pragma once
#include <limits>

namespace constants {
	inline constexpr unsigned ARRAY_SIZE[3] = { 5, 50, 500 };
	inline constexpr unsigned LOWER_LIMIT{ std::numeric_limits<unsigned>::min() };
	inline constexpr unsigned UPPER_LIMIT{ std::numeric_limits<unsigned>::max() };

}