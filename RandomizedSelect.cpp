#include <iostream>
#include <ctime>

template <class T>
int partition(T*a, int p, int r) {
	srand(time(0));
	int t = rand() % (r - p + 1) + p;
	std::swap(a[r], a[t]);
	T x = a[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (a[j] <= x) {
			++i;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[r]);
	return i + 1;
}

template <class T>
T randomSelect(T* A, int p, int r, int i) {
	if (p == r) return A[p];
	int q = partition<T>(A, p, r);
	if (i == q) {
		return A[q];
	} else if (i < q) {
		return randomSelect<T>(A, p, q - 1, i);
	} else {
		return randomSelect<T>(A, q + 1, r, i);
	}
	
}

int main() {
	int a[] = {-7, 11, 3, 2, 8};
	int size = sizeof(a) / sizeof(int);
	std::cout << randomSelect<int>(a, 0, size - 1, 4);
	
	return 0;
}