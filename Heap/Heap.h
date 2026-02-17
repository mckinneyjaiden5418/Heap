#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap {
private:
	int* data;
	int size;
	void bubble_up(int i);
	int parent(int i);

public:
	Heap();
	Heap(const std::vector<int>& arr);
	void insert(int val);
};

#endif
