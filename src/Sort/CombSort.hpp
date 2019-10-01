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
template <typename T, template <typename...> typename __ArrayType>
__ArrayType<T> &comb_sort(__ArrayType<T> &array)
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
	return bubble_sort(array);
}

__ALGO__END__
