#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T, template <typename...> typename __ArrayType>
inline int three_mid(const __ArrayType<T> &array, int first, int last)
{
	if (first >= last)
		return first;
	int l = first, r = last;
	int m = ((r + l) >> 1);
	if (array[l] <= array[m])
	{
		if (array[m] <= array[r])
			return m;
		else if (array[l] <= array[r])
			return r;
		else
			return l;
	}
	else
	{
		if (array[m] >= array[r])
			return m;
		else if (array[l] <= array[r])
			return l;
		else
			return r;
	}
}

template <typename T, template <typename...> typename __ArrayType>
inline int three_mid(const __ArrayType<T> &array)
{
	return three_mid(array, 0, array.size() - 1);
}

template <typename T, template <typename...> typename __ArrayType>
int partition(__ArrayType<T> &array, int first, int last)
{
	if (first >= last)
		return -1;

	// int index = first + Randint() % (last - first);
	int index = three_mid(array, first, last);
	std::swap(array[first], array[index]);

	T pivot = array[first];
	// array_print(array);
	// std::cout << "pivot: " << pivot
	// 		  << " first: " << first
	// 		  << " mid: " << index
	// 		  << " last: " << last
	// 		  << "\n"
	// 		  << std::endl;
	int l = first + 1, r = last;
	while (l <= r)
	{
		if (array[l] <= pivot)
			++l;
		else
			std::swap(array[l], array[r--]);
	}
	std::swap(array[first], array[--l]);
	return l;
}

template <typename T, template <typename...> typename __ArrayType>
inline int partition(__ArrayType<T> &array)
{
	return partition(array, 0, array.size() - 1);
}

template <typename T, template <typename...> typename __ArrayType>
void quick_sort(__ArrayType<T> &array, int low, int high)
{
	if (low >= high)
		return;

	int mid = partition(array, low, high);
	// std::cout << "mid = " << mid << std::endl;
	if (mid > 0)
	{
		if (low < mid)
			quick_sort(array, low, mid - 1);
		if (mid < high)
			quick_sort(array, mid + 1, high);
	}
}

template <typename T, template <typename...> typename __ArrayType>
void quick_sort(__ArrayType<T> &array)
{
	quick_sort(array, 0, array.size() - 1);
}

__ALG__END__
