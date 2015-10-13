#include <iostream>

int get_k_digit(int number, int k) {
	int k_digit = -1;
	for (int i = 1; i <= k; ++i) {
		k_digit = number % 10;
		number /= 10;
	}
	return k_digit;
}

void countSort(int* A, int size, int k, int d) {
	int* C = new int[k + 1];
	int* B = new int[size];
	for (int i = 0; i <= k; ++i) {
		C[i] = 0;
	}
	for (int j = 0; j < size; ++j) {
		++C[get_k_digit(A[j], d)];
	}

	for (int i = 1; i <= k; ++i) {
		C[i] += C[i - 1];
	}
	for (int i = size - 1; i >= 0; --i) {
		B[C[get_k_digit(A[i], d)] - 1] = A[i];
		--C[get_k_digit(A[i], d)];
	}
	for (int i = 0; i < size; ++i) {
		A[i] = B[i];
	}
	
	delete [] B;
	delete [] C;
	
}

void radixSort(int* A, int size, int d) {
	for (int i = 1; i <= d; ++i) {
		countSort(A, size, 9, i);		
	}
}

int main() {
	int A[] = {222, 542, 331, 110, 221, 332, 520, 312};
	int size = sizeof(A) / sizeof(int);
	radixSort(A, size, 9);
/*	for (int i = 0; i < size; ++i)
		std::cout << A[i] << " ";
*/
	return 0;
}