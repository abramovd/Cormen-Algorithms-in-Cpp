#include <iostream>
#include <list>
#include <vector>
#include <math.h>

void bucketSort(double * A, int size) {
	std::vector<std::list<double> > B(size);
	for (int i = 0; i < size; ++i) {
		B[floor((size - 1) * A[i])].push_back(A[i]);
	}
	for (int i = 0; i < size; ++i) {
		B[i].sort();
		if (i >= 1) {
			B[0].merge(B[i]);
		}
	}
	int i = 0;
	for (std::list<double>::iterator it=B[0].begin(); it!=B[0].end(); ++it, ++i)
    	A[i] = *it;
		
}

int main() {
	double a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	int size = sizeof(a) / sizeof(double);
	bucketSort(a, size);
/*
	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << " ";
	}
*/
	return 0;
}