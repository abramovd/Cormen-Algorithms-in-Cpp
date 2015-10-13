#include <iostream>

template <class T>
void insertionSort(T* A, int size) {
    for (int j = 1; j < size; ++j) {
    	T key = A[j];
    	int i = j - 1;
    	while (i > 0 && A[i] > key) {
    		A[i + 1] = A[i];
    		--i;
    	}
    	A[i + 1] = key;
    }
}

int main() {
	int a[] = {-7, 11, 3, 2, 8};
    int size = sizeof(a) / sizeof(int);
    insertionSort<int>(a, size);
/*    for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
*/		
    return 0;
}