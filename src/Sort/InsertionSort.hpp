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
	for (int i = g, j; i < array.size(); i++)
	{
		temp = array[i];
		j = i - g;
		while (j >= 0 and temp < array[j])
		{
			std::swap(array[j + g], array[j]);
			j -= g;
		}
		array[j + g] = temp;
	}
}

__ALG__END__
