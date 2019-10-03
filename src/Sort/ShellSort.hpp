#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam __ArrayType
 * @param array
 * @return __ArrayType<T>&
 */
template <typename T, template <typename...> typename __ArrayType>
void shell_sort(__ArrayType<T> &array)
{
	static unsigned long long Sedgewick[] =
		{1, 5, 19, 41, 109,
		 209, 505, 929, 2161, 3905,
		 8929, 16001, 36289, 64769, 146305,
		 260609, 587521, 1045505, 2354689, 4188161,
		 9427969, 16764929, 37730305, 67084289, 150958081,
		 268386305, 603906049, 1073643521, 2415771649, 4294770689};
	int len = 0;
	while (Sedgewick[len] < array.size())
		++len;

	for (int i = len; i >= 0; --i)
		insertion_sort(array, Sedgewick[i]);
}

__ALG__END__
