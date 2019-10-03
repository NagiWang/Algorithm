#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam __ArrayType
 * @param array
 * @return __ArrayType<T>&
 */
template <typename T, template <typename...> typename __ArrayType>
void shell_sort(__ArrayType<T> &array)
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
}

__ALG__END__
