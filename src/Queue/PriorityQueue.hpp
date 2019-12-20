#pragma once
#include "../Headers.hpp"
#include "../Heap.hpp"

__ALG__BEGIN__

template <typename _elemType, typename _keyType = int, int _size = 32>
class PriorityQueue
{
private:
	int count;
	std::vector<std::pair<_elemType, _keyType>> data;

public:
	PriorityQueue() : data(_size), count(0) {}

	PriorityQueue(std::initializer_list<_elemType> &&init_list) : data(_size), count(0)
	{
		for (auto value : init_list)
		{
			if (count < _size)
				data[count++] = std::move(std::make_pair(value, 0));
			else
				break;
		}
		if (init_list.size() > _size)
			std::cout << RED
					  << "\nThe queue is full! Only retain the first " << _size << " elements.\n"
					  << RESET;
		make_heap(data, 0, count, f_return_pair_first);
	}

	bool isFull() { return count == _size; }
	bool isEmpty() { return count == 0; }
	void print() { std::cout << "top: " << data[0].first
							 << "  key: " << data[0].second
							 << "  count: " << count
							 << std::endl; }

	void insert(const _elemType &value, const _keyType key = 0)
	{
		if (isFull())
		{
			std::cout << RED
					  << "\nWarning: The queue is full! Only retain the first " << _size << " elements.\n"
					  << RESET;
			return;
		}
		std::swap(data[0], data[count++]);
		data[0] = std::make_pair(value, key);
		move_down(data, 0, count, f_return_pair_second);
	}
	void enqueue(const _elemType &value, const _keyType key = 0) { insert(value, key); }

	_elemType top_max()
	{
		if (isEmpty())
		{
			std::cout << RED
					  << "\nWarning: The queue is empty!\n"
					  << RESET;
			return 0;
		}
		else
			return data[0].first;
	}

	_elemType pop_max()
	{
		if (isEmpty())
		{
			std::cout << RED
					  << "\nWarning: The queue is empty!\n"
					  << RESET;
			return 0;
		}
		std::swap(data[0], data[--count]);
		move_down(data, 0, count, f_return_pair_second);
		return data[count + 1].first;
	}
	_elemType dequeue() { return pop_max(); }
};

__ALG__END__
