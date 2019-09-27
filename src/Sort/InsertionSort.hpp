#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

/**
 * @brief
 * TODO:
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @param g
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &insertionSort(_ArrayType<T> &array, int g = 1)
{
	T val;
	for (int i = g, j; i < array.size(); i++)
	{
		val = array[i];
		j = i - g;
		while (j >= 0 and val < array[j])
		{
			std::swap(array[j + g], array[j]);
			j -= g;
		}
		array[j + g] = val;
	}
	return array;
}

__ALGO__END__