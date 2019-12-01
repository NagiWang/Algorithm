#pragma once
#include "../Headers.h"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 */
template <typename _ArrayType, typename _Fn>
void selection_sort(_ArrayType &array, _Fn func)
{
	if (array.empty())
		return;

	for (int i = 0, j, minIndex; i < array.size() - 1; i++)
	{
		for (j = i + 1, minIndex = i; j < array.size(); ++j)
		{
			if (func(array[j]) < func(array[minIndex]))
				minIndex = j;
		}
		std::swap(array[i], array[minIndex]);
	}
}

template <typename _ArrayType>
inline void selection_sort(_ArrayType &array)
{
	selection_sort(array, f_return_itself_value);
}

__ALG__END__
