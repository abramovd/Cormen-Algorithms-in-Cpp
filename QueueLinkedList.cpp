#include <iostream>

template <class T>
class Queue {
private:
	struct node {
		T key;
		node* next;
		node(T x) {
			key = x; next = NULL;
		}
	};
	node* head;
	node* tail;
public:
	Queue() {
		head = NULL;
		tail = NULL;
	}
	bool empty() const{
		return head == 0;
	}
	
	void enqueue(T x) {
		node* t = tail;
		tail = new node(x);
		if (head == NULL) {
			head = tail;
		} else {
			t -> next = tail;
		}
	}

	T dequeue() {
		T item = head->key;
		node* t = head->next;
		delete head;
		head = t;
		return item;
	}

	~Queue() {
		while (head != NULL) {
			node* t = head->next;
			delete head;
			head = t;
		}
//		std::cout << "list destroyed";
	}

};

int main() {
	Queue<int>St;
/*
	St.enqueue(4);
	St.enqueue(3);
	std::cout << St.empty() << St.dequeue() << St.dequeue() << St.empty();
*/
	return 0;
}