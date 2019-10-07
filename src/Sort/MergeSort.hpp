#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <template <typename...> typename _ArrayType, typename T, typename _Fn>
void merge(_ArrayType<T> &array, int first, int last, _Fn &&func)
{
	if (last - first < 2)
		return;

	static T result[10000];
	int mid = (first + last) >> 1;
	int l = first, r = mid, index = 0;
	while (l < mid && r < last)
	{
		if (func(array[l]) <= func(array[r]))
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

template <template <typename...> typename _ArrayType, typename T>
inline void
merge(_ArrayType<T> &array, int first, int last) { merge(array, first, last, f_return_itself_value); }

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param first
 * @param last
 * @param func
 */
template <template <typename...> typename _ArrayType, typename T, typename _Fn>
void merge_sort(_ArrayType<T> &array, int first, int last, _Fn &&func)
{
	if (last - first > 1)
	{
		int mid = (first + last) >> 1;
		merge_sort(array, first, mid, f_return_itself_value);
		merge_sort(array, mid, last, f_return_itself_value);
		merge(array, first, last, f_return_itself_value);
	}
}

template <template <typename...> typename _ArrayType, typename T, typename _Fn>
inline void merge_sort(_ArrayType<T> &array, _Fn &&func)
{
	merge_sort(array, 0, array.size(), func);
}

template <template <typename...> typename _ArrayType, typename T>
inline void merge_sort(_ArrayType<T> &array)
{
	merge_sort(array, f_return_itself_value);
}

__ALG__END__
