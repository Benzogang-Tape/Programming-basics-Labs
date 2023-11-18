#include "Function.h"
#include <iostream>

/*
decltype(std::declval<Tx>() - std::declval<Tk>() * cos(std::declval<Tx>())) Function.equation(Tx x, Tk k) {
	return(x - k * cos(x));
}
*/

/*	Alternative
	template<typename Tx, typename Tk>
	inline auto Function<Tx, Tk>::equation(Tx x, Tk k) -> decltype(std::declval<Tx>() - std::declval<Tk>() * cos(std::declval<Tx>())) {
		return(x - k * cos(x));
	}
*/

template<typename Tx, typename Tk>
inline auto Function<Tx, Tk>::equation(Tx x, Tk k) -> decltype(x - k * std::cos(x)){
	return x - k * std::cos(x);
}