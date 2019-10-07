#include "../../Algorithm.hpp"

int main()
{
	std::vector<int> arr{-10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0,
						 -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, 1};

	alg::array_print(arr);
	alg::move_down(arr);
	alg::array_print(arr);

	// array_print(arr);
	alg::make_heap(arr);
	alg::array_print(arr);

	return 0;
}
