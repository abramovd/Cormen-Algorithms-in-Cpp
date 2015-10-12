#include<iostream>

#define MINF -1000000

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

	Heap(T* a, int n) {
		arr = new T[n];
		for (int i = 0; i < n; ++i)
			arr[i] = a[i];
		size = n;
	}
	void change_size(int new_n) {
		T* temp = new T[new_n];
		for (int i = 0; i < size; ++i)
			temp[i] = arr[i];
		delete [] arr;
		arr = new T[new_n];
		for (int i = 0; i < size; ++i)
			arr[i] = temp[i];
		size = new_n;
		delete [] temp;
	}
	~Heap() {
//		std::cout << "deleating heap!";
		delete [] arr;
	}
};

template <class T>
T heap_maximum(const Heap<T>& h) {
	return h.arr[0];
}

template <class T>
T heap_extract_max(Heap<T>& h) {
	if (h.arr < 1) {
		std::cout << "Queue is empty";
		exit(1);
	}
	
	T max = heap_maximum(h);
	h.arr[0] = h.arr[h.size - 1];
	h.change_size(h.size - 1);
	maxHeapitfy(h, 0);
	return max;
}

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
void heap_increase_key(Heap<T>& h, T key, int i) {
	if (key < h.arr[i]) {
		std::cout << "New key is less then previous";
		exit(1);
	}
	h.arr[i] = key;
	while (i > 0 && h.arr[parent(i)] < h.arr[i]) {
		std::swap(h.arr[parent(i)], h.arr[i]);
		i = parent(i);
	}
}

template <class T>
void heap_insert(Heap<T>& h, T key) {
	h.change_size(h.size + 1);
	h.arr[h.size - 1] = MINF;
	heap_increase_key(h, key, h.size - 1);
}

template <class T>
void print_heap(const Heap<T>& h) {
	for (int i = 0; i < h.size; ++i) {
		std:: cout << h.arr[i] << " ";
	}
}

int main() {
	double a[] = {10.1, -5.2, 6, 7, -3, 10, -2};
	int size = sizeof(a) / sizeof(double);
	
	Heap<double> h = Heap<double>(a, size);

//    print_heap(h);
	
	buildHeap<double>(h);
//	std::cout << "\nafter Build heap\n\n";
//	print_heap(h);
	
//	std::cout << "\nafter insert in heap\n\n";
	heap_insert(h, 4.);
//	print_heap(h);
	
//	std::cout << "\nafter increasing value\n\n";
	heap_increase_key(h, 15., 3);
//	print_heap(h);
	return 0;
}