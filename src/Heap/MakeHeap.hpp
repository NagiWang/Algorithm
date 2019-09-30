#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @param low
 * @param high
 */
template <typename T, template <typename...> typename _ArrayType>
void move_down(_ArrayType<T> &array, int low, int high)
{
	int largest = (low << 1) + 1;
	while (largest <= high)
	{
		if (largest < high and array[largest] < array[largest + 1])
			++largest;
		if (array[low] < array[largest])
		{
			std::swap(array[low], array[largest]);
			low = largest;
			largest = (low << 1) + 1;
		}
		else
			largest = high + 1;
	}
}

/**
 * @brief Floyd Algorithm
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &make_heap(_ArrayType<T> &array)
{
	for (int i = (array.size() >> 1) - 1; i >= 0; --i)
		move_down(array, i, array.size() - 1);

	return array;
}

__ALGO__END__