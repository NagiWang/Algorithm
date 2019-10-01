#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

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
__ArrayType<T> &shell_sort(__ArrayType<T> &array)
{
	std::vector<int> G;
	int g = 0;
	while (g < array.size())
	{
		g = 3 * g + 1;
		G.push_back(g);
	}
	for (int i = array.size() - 1; i >= 0; i--)
	{
		insertion_sort(array, G[i]);
	}
	return array;
}

__ALGO__END__
