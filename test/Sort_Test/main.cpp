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
	std::vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10};

	// * InsertionSort Test
	std::cout << "\nInsertion Sort :" << std::endl;
	array_print(arr);
	alg::insertionSort(arr);
	array_print(arr);

	// * Reverse Arr
	std::reverse(std::begin(arr), std::end(arr));

	// * ShellSort Test
	std::cout << "\nShell Sort :" << std::endl;
	array_print(arr);
	alg::shellSort(arr);
	array_print(arr);

	return 0;
}