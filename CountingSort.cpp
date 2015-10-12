#include <iostream>

void countSort(const int* A, int* B, int size, int k) {
	int* C = new int[k];
	for (int i = 0; i < k; ++i) {
		C[i] = 0;
	}
	for (int j = 0; j < size; ++j) {
		++C[A[j]];
	}
	for (int i = 1; i < k; ++i) {
		C[i] += C[i - 1];
	}
	for (int i = size - 1; i >= 0; --i) {
		B[C[A[i]] - 1] = A[i];
		--C[A[i]];
	}
	delete [] C;
}

int main() {
	int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int size = sizeof(A) / sizeof(int);
	int k = 5;
	int* B = new int[size];
	countSort(A, B, size, k + 1);
/*	for (int i = 0; i < size; ++i) {
		std::cout << B[i] << " ";
	}
*/
	delete [] B;
	return 0;
}