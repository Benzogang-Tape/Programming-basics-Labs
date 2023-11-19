#pragma once
#include <cmath>


template <typename Tx, typename Tk>
struct Function {
	Function();
	inline auto equation(Tx x, Tk k) -> decltype(x - k * std::cos(x));

	/*	Alternative
	{	template <typename Tx, typename Tk>	}
	decltype(std::declval<Tx>() - std::declval<Tk>() * std::cos(std::declval<Tx>()))
	equation(Tx x, Tk k) {
		return(x - k * cos(x));
	}
	*/

	//void print_equation()

};