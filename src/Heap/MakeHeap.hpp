#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @param low
 * @param high
 */
template <typename T, template <typename...> typename __ArrayType>
void move_down(__ArrayType<T> &array, int low, int high)
{
	int largest = (low << 1) + 1;
	while (largest < high)
	{
		if (largest < high - 1 and array[largest] < array[largest + 1])
			++largest;
		if (array[low] < array[largest])
		{
			std::swap(array[low], array[largest]);
			low = largest;
			largest = (low << 1) + 1;
		}
		else
			break;
	}
}

/**
 * @brief
 *
 * @tparam T
 * @tparam __ArrayType
 * @param array
 */
template <typename T, template <typename...> typename __ArrayType>
void make_heap(__ArrayType<T> &array)
{
	for (int i = (array.size() >> 1) - 1; i >= 0; --i)
		move_down(array, i, array.size());

	return;
}

__ALG__END__
