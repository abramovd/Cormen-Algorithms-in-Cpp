#include <iostream>

template <class T>
class Stack {
private:
	struct node {
		T key;
		node* next;
		node(T x, node* t) {
			key = x; next = t;
		}
	};
	typedef node* link;
	link head;
public:
	Stack() {
		head = NULL;
	}
	bool empty() {
		return head == 0;
	}
	
	void push(T x) {
		head = new node(x, head);
	}

	T pop() {
		T item = head->key;
		link t = head->next;
		delete head;
		head = t;
		return item;
	}

	~Stack() {
		while (head != NULL) {
			node* t = head->next;
			delete head;
			head = t;
		}
//		std::cout << "list destroyed";
	}

};

int main() {
	Stack<int>St;
/*
	St.push(4);
	St.push(3);
	std::cout << St.empty() << St.pop() << St.pop() << St.empty();
*/
	return 0;
}