#include <iostream>

template <class T>
class Queue {
private:
	T* S;
	int size, head, tail;
public:
	Queue(int maxN) {
		S = new T[maxN + 1];
		size = maxN + 1;
		head = size;
		tail = 0;
	}
	bool empty() const{
		return head % size == tail;
	}
	
	void enqueue(T x) {
		S[tail++] = x;
		tail %= size;
	}

	T dequeue() {
		head %= size;
		return S[head++];
	}

};

int main() {
	Queue<int>St(5);
/*
	St.enqueue(4);
	St.enqueue(3);
	std::cout << St.empty() << St.dequeue() << St.dequeue() << St.empty();
*/
	return 0;
}