// #include <algorithm>
// #include <iostream>
// #include <iterator>
// #include <random>

// int main()
// {
// 	// std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 	// std::random_device rd;
// 	// std::mt19937 g(rd());

// 	// std::shuffle(v.begin(), v.end(), g);

// 	// std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
// 	// std::cout << "\n";
// }
#include "../Algorithm.h"
#include <complex>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main()
{
	// std::vector<std::pair<int, float>> p1(10);
	// std::cout << "Value-initialized: "
	// 		  << p1[0].first << ", " << p1[0].second << '\n';

	// std::pair<int, double> p2(42, 0.123);
	// std::cout << "Initialized with two values: "
	// 		  << p2.first << ", " << p2.second << '\n';

	// std::pair<char, int> p4(p2);
	// std::cout << "Implicitly converted: "
	// 		  << p4.first << ", " << p4.second << '\n';

	// std::pair<std::complex<double>, std::string> p6(
	// 	std::piecewise_construct,
	// 	std::forward_as_tuple(0.123, 7.7),
	// 	std::forward_as_tuple(10, 'a'));
	// std::cout << "Piecewise constructed: "
	// 		  << p6.first << ", " << p6.second << '\n';
	static_assert(std::is_same<alg::ArrayPtr_t<int[5], 1>, int **>::value, "Hi~");
	// static_assert(std::is_same<typename alg::_AddArrayPointer<int[5], 4, 3>::type, int **>::value, "Hi~");
}
