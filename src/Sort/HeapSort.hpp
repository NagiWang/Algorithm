#pragma once
#include "../Headers.hpp"
#include "../Heap.hpp"

__ALGO__BEGIN__

template <typename T, template <typename...> typename _ArrayType>
_ArrayType<T> &heap_sort(_ArrayType<T> &array)
{
	for (int i = (array.size() >> 1) - 1; i >= 0; --i)
		move_down(array, i, array.size() - 1);
	for (int i = array.size() - 1; i >= 1; --i)
	{
		std::swap(array[0], array[i]);
		move_down(array, 0, i - 1);
	}
	return array;
}

__ALGO__END__