#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T, template <typename...> typename _ArrayType>
void merge(_ArrayType<T> &array, const int first, const int last)
{
	if (last - first < 2)
		return;

	static T result[10000];
	int mid = (first + last) >> 1;
	int l = first, r = mid, index = 0;
	while (l < mid && r < last)
	{
		if (array[l] <= array[r])
			result[index++] = array[l++];
		else
			result[index++] = array[r++];
	}

	while (l < mid)
		result[index++] = array[l++];

	while (r < last)
		result[index++] = array[r++];

	for (int i = first; i < last; i++)
		array[i] = result[i - first];
	// alg::array_print(array);
}

template <typename T, template <typename...> typename _ArrayType>
void merge_sort(_ArrayType<T> &array, int first, int last)
{
	if (last - first > 1)
	{
		int mid = (first + last) >> 1;
		merge_sort(array, first, mid);
		merge_sort(array, mid, last);
		merge(array, first, last);
	}
}

template <typename T, template <typename...> typename _ArrayType>
void merge_sort(_ArrayType<T> &array)
{
	merge_sort(array, 0, array.size());
}

__ALG__END__
