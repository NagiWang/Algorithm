#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

__ALGO__BEGIN__

/*
 * Shell Sort
 * TODO:
 */
template <typename T, template <typename...> typename ARRAY_>
ARRAY_<T> &shellSort(ARRAY_<T> &array)
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
		alg::insertionSort(array, G[i]);
	}
	return array;
}

__ALGO__END__