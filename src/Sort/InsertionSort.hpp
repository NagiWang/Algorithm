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
 * @param g
 * @param func
 */
template <template <typename...> typename _ArrayType, typename T, typename _Fn>
void insertion_sort(_ArrayType<T> &array, int g, _Fn func)
{
	T temp;
	for (int k = g; k < (g << 1); ++k)
		for (int i = k, j; i < array.size();)
		{
			temp = array[i];
			for (j = i; j - g >= 0 and func(temp) < func(array[j - g]); j -= g)
				array[j] = array[j - g];

			array[j] = temp;
			i += g;
		}
}

template <template <typename...> typename _ArrayType, typename T, typename _Fn>
inline void insertion_sort(_ArrayType<T> &array, _Fn func)
{
	insertion_sort(array, 1, func);
}

template <template <typename...> typename _ArrayType, typename T>
inline void insertion_sort(_ArrayType<T> &array)
{
	insertion_sort(array, 1, f_return_itself_value);
}

__ALG__END__
