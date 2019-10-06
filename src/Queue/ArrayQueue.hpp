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
	ArrayQueue(std::initializer_list<T> init_list) : first(-1), last(), count(0)
	{

		for (auto value : init_list)
		{
			if (count <= _size)
				data[count++] = value;
		}
		if (count > _size)
			std::cout << RED
					  << "\nThe queue is full! Only retain the first " << _size << " elements.\n"
					  << RESET;
		last = count - 1;
	}

	bool isFull() { return count == _size; }
	bool isEmpty() { return count == 0; }

	void print() { std::cout << "first: " << first
							 << " last : " << last
							 << " count: " << count
							 << std::endl; }

	void enqueue(const T &value)
	{
		if (isFull())
		{
			std::cout << RED
					  << "\nWarning: The queue is full! Only retain the first " << _size << " elements.\n"
					  << RESET;
			return;
		}
		last = (last + 1) % _size;
		data[last] = value;
		++count;
		//* print(); // for debugging
	}

	T dequeue()
	{
		if (isEmpty())
		{
			std::cout << RED
					  << "\nWarning: The queue is empty!\n"
					  << RESET;
			return 0;
		}
		first = (first + 1) % _size;
		--count;
		//* print(); // for debugging
		return data[first];
	}
};

__ALG__END__
