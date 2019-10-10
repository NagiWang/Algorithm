#include "../../Algorithm.hpp"

int main()
{
	alg::PriorityQueue<int> que;
	// alg::ListQueue<int> que;
	for (int i = 0; i < 48; ++i)
	{
		que.enqueue(i);
		que.print();
	}

	for (int i = 0; i < 16; ++i)
	{
		que.dequeue();
		que.print();
	}
	// std::cout << que.dequeue() << " ";

	std::cout << std::endl;
	for (int i = 32; i < 48; ++i)
	{
		que.enqueue(i);
		que.print();
	}

	for (int i = 0; i < 48; ++i)
	{
		que.dequeue();
		que.print();
	}
	// std::cout << que.dequeue() << " ";

	std::cout << std::endl;
	for (int i = 16; i < 48; ++i)
	{
		que.enqueue(i);
		que.print();
	}

	for (int i = 0; i < 33; ++i)
	{
		que.dequeue();
		que.print();
	}
	std::cout << std::endl;

	return 0;
}
