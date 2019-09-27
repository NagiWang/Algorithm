#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

/**
 * @brief selection sort
 * TODO:
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &selectionSort(_ArrayType<T> &array)
{
	for (int i = 0, j, minIndex; i < array.size() - 1; i++)
	{
		for (j = i + 1, minIndex = i; j < array.size(); ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(array[i], array[minIndex]);
	}
	return array;
}

__ALGO__END__