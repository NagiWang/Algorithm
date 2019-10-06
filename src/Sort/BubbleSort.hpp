#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__


template <typename T, template <typename...> typename _ArrayType>
void bubble_sort(_ArrayType<T> &array, int g = 1)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int j = array.size() - 1; j > 0; --j)
		{
			if (array[j] < array[j - 1])
			{
				std::swap(array[j], array[j - 1]);
				flag = false;
			}
		}
	}
}

__ALG__END__
