#include <iostream>

template <class T>
class LinkedList {
private:
	struct node {
		T data;
		node* next;
	};
	node* head;
public:
	LinkedList() {
		head = NULL;
	}
	
	void push(T key) {
		node* new_node = new node;
		new_node->data = key;
		new_node->next = NULL;
		if (head == NULL) {
			head = new_node;
			return;
		}
		new_node->next = head;
		head = new_node;
	}

	void print() {
		node* current = head;
		while (current != NULL) {
			std::cout << current->data << " ";
			current = current->next;
		}
	}

	void reverseLL() {
		if (head == NULL) return;
		node* current = head;
		node* prev = NULL;
		node* next = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

};

int main() {
	LinkedList<int> ll;
	ll.push(5);
	ll.push(6);
	ll.push(4);
	ll.print();
	ll.reverseLL();
	ll.print();
	return 0;
}