#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

#ifndef __ALG__BEGIN__
#define __ALG__BEGIN__ \
	namespace alg      \
	{
#endif

#ifndef __ALG__END__
#define __ALG__END__ \
	}                \
	;
#endif

__ALG__BEGIN__

/**
 * @brief Generate Random Number
 *
 * @return int
 */
int Randint()
{
	static std::default_random_engine e(time(0));
	return e();
}

template <typename T>
void array_print(const T &array)
{
	if constexpr (1)
	{
		if (array.size() > 30)
		{
			for (int i = 0; i < 30; ++i)
				std::cout << array[i] << " ";
			std::cout << std::endl;
			return;
		}

		for (auto val : array)
			std::cout << val << " ";
		std::cout << std::endl;
	}
}

__ALG__END__
