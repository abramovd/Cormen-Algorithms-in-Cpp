#include<iostream>

#define MinInt -1000000

struct Str {
	int low;
	int high;
	int sum;
};

std::ostream& operator<<(std::ostream& out, const Str& st) {
	out << st.low << " " << st.high << " " << st.sum; 
	return out;
};

Str findCrossSubArray(const int* arr, int low, int high) {
	// cross the middle element
	Str s;
	int mid = (low + high) / 2;
	
	int left_sum = MinInt;
	int sum = 0;
	int max_left = -1;
	
	for (int i = mid; i >= low; --i) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = MinInt;
	sum = 0;
	int max_right = -1;
	
	for (int i = mid + 1; i <= high; ++i) {
		sum += arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	
	s.low = max_left;
	s.high = max_right;
	s.sum = left_sum + right_sum;
	return s;
}

Str findMaxSubArray (const int* arr, int low, int high) {
	Str s;
	int mid = (low + high) / 2;
	if (low == high) {
		s.low = low;
		s.high = high;
		s.sum = arr[low];
		return s;
	}
	
	Str s_left = findMaxSubArray(arr, low, mid);
	Str s_right = findMaxSubArray(arr, mid + 1, high);
	Str s_cross = findCrossSubArray(arr, low, high);
	
	if (s_left.sum >= s_cross.sum && s_left.sum >= s_right.sum)
		return s_left;
	else if (s_right.sum >= s_cross.sum && s_right.sum >= s_left.sum)
		return s_right;
	else return s_cross;
	
}

int main() {
	int a[] = {10, -5, 6, 7, -3, 10, -2};
	int size = sizeof(a) / sizeof(int);
	std::cout << findMaxSubArray(a, 0, size - 1);
	return 0;
}