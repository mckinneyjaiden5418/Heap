#include "Heap.h"
#include <vector>

void Heap::bubble_up(int i) {
	while (i > 0) {
		int j = parent(i);
		if (data[j] < data[i]) {
			int temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		else {
			return;
		}
		
		i = j;
	}
}

int Heap::parent(int i) {
	return (i - 1) / 2;
}

Heap::Heap() {
	data = new int[20];
	size = 0;
}

Heap::Heap(const std::vector<int>& arr) {

}

void Heap::insert(int val) {
	data[size] = val;
	size++;
	bubble_up(size - 1);
}