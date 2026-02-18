#include "Heap.h"
#include <vector>
#include <iostream>

void Heap::resize(int n) {
	int* temp = new int[n];
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}

	cap = n;
	delete[] data;
	data = temp;
}

void Heap::swap_at(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}


void Heap::bubble_up(int i) {
	while (i > 0) {
		int j = parent(i);
		if (data[j] < data[i]) {
			swap_at(i, j);
		}
		else {
			return;
		}
		
		i = j;
	}
}

void Heap::bubble_down(int i) {
	while (true) {
		int l = left(i);
		int r = right(i);
		int largest = i;

		if (l < size && data[i] < data[l]) {
			largest = l;
		}

		if (r < size && data[largest] < data[r]) {
			largest = r;
		}

		if (largest == i) {
			return;
		}

		swap_at(i, largest);
		i = largest;
	}
}

int Heap::parent(int i) {
	return (i - 1) / 2;
}

int Heap::left(int i) {
	return 2 * i + 1;
}

int Heap::right(int i) {
	return 2 * i + 2;
}

void Heap::build_heap_top_down(const int arr[], int n) {
	for (int i = 0; i < n; i++) {
		insert(arr[i]);
	}
}

void Heap::build_heap_bottom_up(const int arr[], int n) {
	for (int i = 0; i < n; i++) {
		data[i] = arr[i];
	}

	size = n;
	for (int i = n - 1; i >= 0; i--) {
		bubble_down(i);
	}

}

Heap::Heap() {
	data = new int[20];
	size = 0;
	cap = 20;
}

Heap::Heap(const int arr[], int n) {
	size = 0;
	cap = n;
	if (n == 0) {
		cap = 20;
	}

	data = new int[cap];
	// build_heap_top_down(arr, n);
	build_heap_bottom_up(arr, n);
}

void Heap::insert(int val) {
	if (cap == 20) {
		resize(cap * 2);
	}
	data[size] = val;
	size++;
	bubble_up(size - 1);
}

int Heap::extract() {
	if (size == 0) {
		std::cout << "Heap is empty" << std::endl;
		return -1;
	}

	int root = data[0];
	swap_at(0, size - 1);
	size--;
	bubble_down(0);

	return root;
}

void Heap::display() {
	std::cout << "Displaying Heap" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}