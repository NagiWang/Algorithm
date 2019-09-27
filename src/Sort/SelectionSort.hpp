#pragma once
#include "../Headers.hpp"

__ALGO__BEGIN__

template <typename T, template <typename...> typename _ARRAY_>
_ARRAY_<T> &selectionSort(_ARRAY_<T> &array)
{
	for (int i = 0, j, minIndex; i < array.size() - 1; i++)
	{
		for (j = i + 1, minIndex = i; j < array.size(); ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(array[i], array[minIndex]);
	}
	return array;
}

__ALGO__END__