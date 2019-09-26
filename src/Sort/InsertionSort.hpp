#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

/*
 * Insertion Sort
 * Best    : O ( n^2 )
 * Average : O ( n^2 )
 * Worst   : O ( n^2 )
 */
template <typename T>
std::vector<T> &insertionSort(std::vector<T> &array, int g = 1)
{
	T val;
	int j;
	for (int i = g; i < array.size(); i++)
	{
		val = array[i];
		j = i - g;
		while (j >= 0 and val < array[j])
		{
			std::swap(array[j + g], array[j]);
			j -= g;
		}
		array[j + g] = val;
	}
	return array;
}

__ALGO__END__