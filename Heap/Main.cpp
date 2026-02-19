#include "Heap.h"

int main() {
	Heap* heap = new Heap();
	heap->insert(10);
	heap->insert(20);
	heap->insert(15);
	heap->insert(22);
	heap->display();

	heap->extract();
	heap->display();
	heap->extract();
	heap->display();
	heap->extract();
	heap->display();
	heap->extract();
	heap->display();

	int A[] = {1, 2, 3, 4, 5};
	Heap* heap_array = new Heap(A, 5);
	heap_array->display();

	heap_array->heap_sort();
	delete heap;
	delete heap_array;
	return 0;
}