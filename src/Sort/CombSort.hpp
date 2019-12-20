#pragma once
#include "../Headers.hpp"
#include "BubbleSort.hpp"

__ALG__BEGIN__

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
void comb_sort(_ArrayType &array, _Fn func)
{
	int step = array.size(), j, k;
	while ((step = int(step / 1.3)) > 1)
	{
		for (j = array.size() - 1; j >= step; --j)
		{
			k = j - step;
			if (func(array[j]) < func(array[k]))
				std::swap(array[j], array[k]);
		}
	}
	bubble_sort(array);
}

template <typename _ArrayType>
inline void comb_sort(_ArrayType &array)
{
	comb_sort(array, f_return_itself_value);
}

__ALG__END__
