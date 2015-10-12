#include <iostream>
#include <ctime>

template <class T>
int partition(T*a, int p, int r) {
	srand(time(0));
	int t = rand() % r + p;
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
void quickSort(T* a, int p, int r) {

	if (p < r) {
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int main() {
	double a[] = {10.1, -5.2, 6, 7, -3, 10, -2};
	int size = sizeof(a) / sizeof(double);
	quickSort<double>(a, 0, size - 1);
/*	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
*/
	return 0;
}