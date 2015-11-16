#include <iostream>

#define INF 10000000

template <class T>
void merge(T* A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int* Left = new T [n1 + 1];
	int* Right = new T [n2 + 1];
	
	for (int i = 0; i < n1; ++i) {
		Left[i] = A[p + i];
	}
	
	for (int i = 0; i < n2; ++i) {
		Right[i] = A[q + 1 + i];
	}
	
	Left[n1] = INF;
	Right[n2] = INF;
	
	int i = 0, j = 0;
	for (int k = 0; k <= r; ++k) {
		if (Left[i] <= Right[j]) {
			A[k] = Left[i];
			++i;
		} else {
			A[k] = Right[j];
			++j;
		}	
	}
	
	delete [] Left;
	delete [] Right;
	
}

template <class T>
void merge_sort(T* A, int p, int r) {
	if (r - p > 1) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}

}

int main() {
	int a[] = {-7, 11, 3, 2, 8};
    int size = sizeof(a) / sizeof(int);
	merge_sort<int>(a, 0, size - 1);
/*
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
*/
    return 0;
	
}