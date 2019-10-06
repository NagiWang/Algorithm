#pragma once
#include "../Headers.hpp"

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
template <typename T, template <typename...> typename _ArrayType, typename _Fn>
void move_down(_ArrayType<T> &array, int low, int high, _Fn func)
{
	int largest = (low << 1) + 1;
	while (largest < high)
	{
		if (largest < high - 1 and func(array[largest]) < func(array[largest + 1]))
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

template <typename T, template <typename...> typename _ArrayType>
inline void move_down(_ArrayType<T> &array, int low, int high)
{
	move_down(array, low, high,
			  [](T &value) -> T & { return value; });
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
template <typename T, template <typename...> typename _ArrayType, typename _Fn>
void make_heap(_ArrayType<T> &array, _Fn func)
{
	for (int i = (array.size() >> 1) - 1; i >= 0; --i)
		move_down(array, i, array.size(), func);
}

template <typename T, template <typename...> typename _ArrayType>
inline void make_heap(_ArrayType<T> &array)
{
	make_heap(array,
			  [](T &value) -> T & { return value; });
}

__ALG__END__
