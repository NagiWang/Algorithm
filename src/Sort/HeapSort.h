#pragma once
#include "../Headers.h"
#include "../Heap.h"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param func
 */
template <typename _ArrayType, typename _Fn>
void heap_sort(_ArrayType &array, _Fn func)
{
	make_heap(array, func);

	for (int i = array.size() - 1; i >= 1; --i)
	{
		std::swap(array[0], array[i]);
		move_down(array, 0, i - 1, func);
	}
}

template <typename _ArrayType>
inline void heap_sort(_ArrayType &array)
{
	heap_sort(array, f_return_itself_value);
}

__ALG__END__
