#pragma once
#include "../Headers.hpp"
#include "../Heap.hpp"

__ALG__BEGIN__

template <typename _keyType, typename _elemType, int _size = 32>
class PriorityQueue
{
private:
	int count;
	std::vector<std::pair<_keyType, _elemType>> data();

public:
	PriorityQueue() : count{0} {}

	PriorityQueue(std::initializer_list<std::pair<_keyType, _elemType>> init_list) : count{0}
	{
		for (auto value : init_list)
		{
			if (count <= _size)
				data[count++] = value;
			else
				break;
		}
		if (count > _size)
			std::cout << RED
					  << "\nThe queue is full! Only retain the first " << _size << " elements.\n"
					  << RESET;
		make_heap()
	}
};

__ALG__END__
