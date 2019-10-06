#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 */
template <typename T, template <typename...> typename _ArrayType>
void selection_sort(_ArrayType<T> &array)
{
	if (array.empty())
		return;

	for (int i = 0, j, minIndex; i < array.size() - 1; i++)
	{
		for (j = i + 1, minIndex = i; j < array.size(); ++j)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		std::swap(array[i], array[minIndex]);
	}
}

__ALG__END__
