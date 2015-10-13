#include <iostream>

template <class T>
class Stack {
private:
	T* S;
	int size;
public:
	Stack(int maxN) {
		S = new T[maxN];
		size = 0;
	}
	bool empty() const{
		return size == 0;
	}
	
	void push(T x) {
		S[size++] = x;
	}

	T pop() {
		return S[--size];
	}
};

int main() {
	Stack<int>St(5);
/*
	St.push(4);
	St.push(3);
	std::cout << St.empty() << St.pop() << St.pop() << St.empty();
*/
	return 0;
}