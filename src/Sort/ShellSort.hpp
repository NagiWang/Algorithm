#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @param i
 * @return unsigned long long&
 */
unsigned long long &Sedgewick(int i)
{
	static unsigned long long sedgewick[] =
		{1, 5, 19, 41, 109,
		 209, 505, 929, 2161, 3905,
		 8929, 16001, 36289, 64769, 146305,
		 260609, 587521, 1045505, 2354689, 4188161,
		 9427969, 16764929, 37730305, 67084289, 150958081,
		 268386305, 603906049, 1073643521, 2415771649, 4294770689};

	return sedgewick[i];
}

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param func
 */
template <typename _ArrayType, typename _Fn>
void shell_sort(_ArrayType &array, _Fn func)
{
	int len = 0;
	while (Sedgewick(len) < array.size())
		++len;

	for (int i = len - 1; i >= 0; --i)
		insertion_sort(array, Sedgewick(i), func);
}

template <typename _ArrayType>
inline void shell_sort(_ArrayType &array)
{
	shell_sort(array, f_return_itself_value);
}

__ALG__END__
