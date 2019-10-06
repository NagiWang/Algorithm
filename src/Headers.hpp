#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
#include <list>
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

#define RESET "\033[0m"
#define BLACK "\033[30m"			  /* Black */
#define RED "\033[31m"				  /* Red */
#define GREEN "\033[32m"			  /* Green */
#define YELLOW "\033[33m"			  /* Yellow */
#define BLUE "\033[34m"				  /* Blue */
#define MAGENTA "\033[35m"			  /* Magenta */
#define CYAN "\033[36m"				  /* Cyan */
#define WHITE "\033[37m"			  /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"	 /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"	/* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"	/* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

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
