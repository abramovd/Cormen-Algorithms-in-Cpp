#include<iostream>

int parent(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return 2 * i + 1;
}

template <class T>
struct Heap {
	T* arr;
	int size;
	//int heap_size;
	Heap(int* a, int n) {
		arr = a;
		size = n;
	}
};

template<class T>
void maxHeapify(Heap<T>& h, int i) {
	// O(lgN)
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < h.size && h.arr[l] > h.arr[i]) largest = l;
	if (r < h.size && h.arr[r] > h.arr[largest]) largest = r;
	if (largest != i) {
		std::swap(h.arr[i], h.arr[largest]);
		maxHeapify(h, largest);
	}
}

template<class T>
void buildHeap(Heap<T>&h) {
	// O(N)
	//h.heap_size = h.size;
	for (int i = h.size / 2 - 1; i >= 0; --i)
		maxHeapify(h, i);
}

template <class T>
void heapSort(int* arr, int n) {
	// O(N lg N)
	Heap<T> h(arr, n);
	buildHeap(h);
	for (int i = h.size - 1; i >= 1; --i) {
		std::swap(h.arr[0], h.arr[i]);
		--h.size;
		maxHeapify(h, 0);
	}
}

int main() {
	int a[] = {10, -5, 6, 7, -3, 10, -2};
	int size = sizeof(a) / sizeof(int);
	heapSort<int>(a, size);
/*	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << " ";
	}
*/
	return 0;
}