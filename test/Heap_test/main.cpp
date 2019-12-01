#include "../../Algorithm.h"

int main()
{
	std::vector<int> arr{-10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 10,
						 -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, 20};

	alg::array_print(arr);
	alg::move_down(arr);
	alg::array_print(arr);

	std::random_shuffle(std::begin(arr), std::end(arr));
	alg::array_print(arr);
	alg::make_heap(arr);
	alg::array_print(arr);

	// auto t = alg::remove_array_type(arr);
	// t.type a = 123;
	// std::cout << typeid(a).name() << std::endl;
	return 0;
}
