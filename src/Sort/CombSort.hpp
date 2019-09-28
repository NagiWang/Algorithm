#pragma once
#include "../Headers.hpp"
#include "BubbleSort.hpp"

__ALGO__BEGIN__

/**
 * @brief
 * TODO:
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &combSort(_ArrayType<T> &array)
{
	int step = array.size(), j, k;
	while ((step = int(step / 1.3)) > 1)
	{
		for (j = array.size() - 1; j >= step; --j)
		{
			k = j - step;
			if (array[j] < array[k])
				std::swap(array[j], array[k]);
		}
	}
	return alg::bubbleSort(array);
}

__ALGO__END__