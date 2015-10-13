#include <iostream>

void countSort(int* A, int size, int k) {
    int* B = new int[size];
	int* C = new int[k + 1];
	for (int i = 0; i <= k; ++i) {
		C[i] = 0;
	}
	for (int j = 0; j < size; ++j) {
		++C[A[j]];
	}
	for (int i = 1; i <= k; ++i) {
		C[i] += C[i - 1];
	}
	for (int i = size - 1; i >= 0; --i) {
		B[C[A[i]] - 1] = A[i];
		--C[A[i]];
	}
    for (int i = 0; i < size; ++i) {
        A[i] = B[i];
    }
    delete [] B;
	delete [] C;
}

int main() {
	int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int size = sizeof(A) / sizeof(int);
	int k = 5;
	countSort(A, size, k);
/*	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
*/	
	return 0;
}