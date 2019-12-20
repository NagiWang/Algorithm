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
template <typename _ArrayType, typename _Fn>
void bubble_sort(_ArrayType &array, int g, _Fn func)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int j = array.size() - 1; j > 0; --j)
		{
			if (func(array[j]) < func(array[j - 1]))
			{
				std::swap(array[j], array[j - 1]);
				flag = false;
			}
		}
	}
}

template <typename _ArrayType>
inline void bubble_sort(_ArrayType &array)
{
	bubble_sort(array, 1, f_return_itself_value);
}

__ALG__END__
