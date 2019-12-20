#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T>
class ListQueue
{
private:
	std::list<T> lst;

public:
	ListQueue() : lst() {}
	ListQueue(std::initializer_list<T> init_list) : lst(init_list) {}
	// bool isFull() { return count == _size; }
	void print() { std::cout << "Size: " << lst.size() << std::endl; }
	bool isEmpty() { return lst.empty(); }

	void enqueue(const T &value) { lst.push_back(value); }
	T dequeue()
	{
		if (isEmpty())
		{
			std::cout << RED
					  << "\nWarning: The queue is empty!\n"
					  << RESET;
			return 0;
		}
		T value = lst.front();
		lst.pop_front();
		return value;
	}
};

__ALG__END__
