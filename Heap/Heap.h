#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
	int* data;
	int size;
	int cap;
	void resize(int n);
	void swap_at(int i, int j);
	void bubble_up(int i);
	void bubble_down(int i);
	int parent(int i);
	int left(int i);
	int right(int i);
	void build_heap_top_down(const int arr[], int n);
	void build_heap_bottom_up(const int arr[], int n);

public:
	Heap();
	Heap(const int arr[], int n);
	void insert(int val);
	void display();
	int extract();
	void heap_sort();
};

#endif
