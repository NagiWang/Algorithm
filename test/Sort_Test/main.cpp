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
	std::vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
						 -1, 2, -3, 4, -5, 6, -7, 8, -9, 10};

	//* Bubble Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nBubble Sort :" << std::endl;
	array_print(arr);
	alg::bubbleSort(arr);
	array_print(arr);

	//* Comb Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nComb Sort :" << std::endl;
	array_print(arr);
	alg::combSort(arr);
	array_print(arr);

	//* Insertion Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nInsertion Sort :" << std::endl;
	array_print(arr);
	alg::insertionSort(arr);
	array_print(arr);

	//* Selection Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nSelection Sort :" << std::endl;
	array_print(arr);
	alg::selectionSort(arr);
	array_print(arr);

	//* Shell Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nShell Sort :" << std::endl;
	array_print(arr);
	alg::shellSort(arr);
	array_print(arr);

	return 0;
}