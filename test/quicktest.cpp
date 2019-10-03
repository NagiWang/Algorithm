#include "../Algorithm.hpp"

int main()
{
	std::vector<int> arr{-10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0,
						 -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, 0};

	alg::array_print(arr);
	std::cout << arr[alg::three_mid(arr)] << std::endl;
	int index = alg::partition(arr);
	std::cout << index << std::endl;
	std::cout << arr[index] << std::endl;
	alg::array_print(arr);
	alg::quick_sort(arr);
	alg::array_print(arr);

	return 0;
}
