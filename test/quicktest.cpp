#include "../Algorithm.hpp"

int main()
{
	std::vector<int> arr{-9, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0,
						 -8, 8, -7, 7, -5, 5, -3, 3, -1, 1, 0};

	// alg::array_print(arr);
	// std::cout << arr[alg::three_mid(arr)] << std::endl;
	// int index = alg::partition(arr);
	// std::cout << index << std::endl;
	// std::cout << arr[index] << std::endl;
	// alg::array_print(arr);
	// alg::quick_sort(arr);
	// alg::array_print(arr);

	alg::array_print(arr);
	// alg::merge(arr, 0, arr.size());
	alg::merge_sort(arr);
	// alg::array_print(arr);
	alg::array_print(arr);

	return 0;
}

