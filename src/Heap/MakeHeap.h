#pragma once
#include "../Headers.h"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param low
 * @param high
 * @param func
 */
template <typename _ArrayType, typename _Fn>
void move_down(_ArrayType &array, int low, int high, _Fn func)
{
	int largest = (low << 1) + 1;
	while (largest < high)
	{
		if (largest < high - 1 && func(array[largest]) < func(array[largest + 1]))
			++largest;
		if (func(array[low]) < func(array[largest]))
		{
			std::swap(array[low], array[largest]);
			low = largest;
			largest = (low << 1) + 1;
		}
		else
			break;
	}
}

template <typename _ArrayType>
inline void move_down(_ArrayType &array, int low, int high)
{
	move_down(array, low, high, f_return_itself_value);
}

template <typename _ArrayType>
inline void move_down(_ArrayType &array)
{
	move_down(array, 0, array.size(), f_return_itself_value);
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
void make_heap(_ArrayType &array, int first, int last, _Fn func)
{
	for (int i = (array.size() >> 1) - 1; i >= 0; --i)
		move_down(array, first, last, func);
}

template <typename _ArrayType, typename _Fn>
void make_heap(_ArrayType &array, _Fn func)
{
	make_heap(array, 0, array.size(), func);
}

template <typename _ArrayType>
inline void make_heap(_ArrayType &array)
{
	make_heap(array, f_return_itself_value);
}

__ALG__END__
