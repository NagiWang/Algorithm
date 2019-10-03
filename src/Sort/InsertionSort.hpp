#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam __ArrayType
 * @param array
 * @param g
 */
template <typename T, template <typename...> typename __ArrayType>
void insertion_sort(__ArrayType<T> &array, int g = 1)
{
	T temp;
	for (int k = g; k < (g << 1) ; ++k)
		for (int i = k, j; i < array.size();)
		{
			temp = array[i];
			for (j = i; j - g >= 0 and temp < array[j - g]; j -= g)
				array[j] = array[j - g];

			array[j] = temp;
			i += g;
		}
}

__ALG__END__
