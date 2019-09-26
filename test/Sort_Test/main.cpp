#include "../../Algorithm.hpp"

template <typename T>
void array_print(const T &array)
{
	for (auto val : array)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	std::cout << "\nInsertion Sort :" << std::endl;
	array_print(arr);
	alg::insertionSort(arr);
	array_print(arr);

	std::reverse(std::begin(arr), std::end(arr));

	std::cout << "\nShell Sort :" << std::endl;
	array_print(arr);
	alg::shellSort(arr);
	array_print(arr);

	return 0;
}