#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

/**
 * @brief bubble sort
 * TODO:
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &bubble_sort(_ArrayType<T> &array, int g = 1)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int j = array.size() - 1; j > 0; --j)
		{
			if (array[j] < array[j - 1])
			{
				std::swap(array[j], array[j - 1]);
				flag = false;
			}
		}
	}
	return array;
}

__ALGO__END__