#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _size default = 32
 */
template <typename T, int _size = 32>
class ArrayQueue
{
private:
	int first, last, count;
	T data[_size];

public:
	ArrayQueue() : first(-1), last(-1), count(0) {}

	bool isFull() { return count == _size; }
	bool isEmpty() { return count == 0; }

	void print() { std::cout << "first: " << first
							 << " last : " << last
							 << " count: " << count
							 << std::endl; }

	void enqueue(const T &value)
	{
		if (isFull())
			return;
		last = (last + 1) % _size;
		data[last] = value;
		++count;
		//* print(); // for debugging
	}

	T dequeue()
	{
		if (isEmpty())
		{
			std::cout << RED << "\nWarning: The queue is empty!"
					  << RESET << std::endl;
			return 0;
		}
		first = (first + 1) % _size;
		--count;
		//* print(); // for debugging
		return data[first];
	}
};

__ALG__END__
