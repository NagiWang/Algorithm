#include "../../Algorithm.hpp"

int main()
{
	std::vector<int> arr{};
	for (int i = 0; i < 10000; ++i)
		arr.push_back(i);

	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds;
	std::time_t end_time;

	// //* Bubble Sort Test
	// //* Random Shuffle Arr
	// std::random_shuffle(std::begin(arr), std::end(arr));
	// std::cout << "\nBubble Sort :" << std::endl;
	// alg::array_print(arr);
	// start = std::chrono::system_clock::now();
	// alg::bubble_sort(arr);
	// end = std::chrono::system_clock::now();
	// alg::array_print(arr);
	// elapsed_seconds = end - start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	//* Comb Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nComb Sort :" << std::endl;
	alg::array_print(arr);
	start = std::chrono::system_clock::now();
	alg::comb_sort(arr);
	end = std::chrono::system_clock::now();
	alg::array_print(arr);
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	//* Heap Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nHeap Sort :" << std::endl;
	alg::array_print(arr);
	start = std::chrono::system_clock::now();
	alg::heap_sort(arr);
	end = std::chrono::system_clock::now();
	alg::array_print(arr);
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	// //* Insertion Sort Test
	// //* Random Shuffle Arr
	// std::random_shuffle(std::begin(arr), std::end(arr));
	// std::cout << "\nInsertion Sort :" << std::endl;
	// alg::array_print(arr);
	// start = std::chrono::system_clock::now();
	// alg::insertion_sort(arr);
	// end = std::chrono::system_clock::now();
	// alg::array_print(arr);
	// elapsed_seconds = end - start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	//* Merge Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nMerge Sort :" << std::endl;
	alg::array_print(arr);
	start = std::chrono::system_clock::now();
	alg::merge_sort(arr);
	end = std::chrono::system_clock::now();
	alg::array_print(arr);
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	//* Quick Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nQuick Sort :" << std::endl;
	alg::array_print(arr);
	start = std::chrono::system_clock::now();
	alg::quick_sort(arr);
	end = std::chrono::system_clock::now();
	alg::array_print(arr);
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	// //* Selection Sort Test
	// //* Random Shuffle Arr
	// std::random_shuffle(std::begin(arr), std::end(arr));
	// std::cout << "\nSelection Sort :" << std::endl;
	// alg::array_print(arr);
	// start = std::chrono::system_clock::now();
	// alg::selection_sort(arr);
	// end = std::chrono::system_clock::now();
	// alg::array_print(arr);
	// elapsed_seconds = end - start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	//* Shell Sort Test
	//* Random Shuffle Arr
	std::random_shuffle(std::begin(arr), std::end(arr));
	std::cout << "\nShell Sort :" << std::endl;
	alg::array_print(arr);
	start = std::chrono::system_clock::now();
	alg::shell_sort(arr);
	end = std::chrono::system_clock::now();
	alg::array_print(arr);
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}
