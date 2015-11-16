#include <iostream>

template <class T>
class ChainedHash {
private:
	int m;
	struct node {
		T key;
		node* next;
		node* prev;
		node() {
			next = NULL;
			prev = NULL;
		}
	};
		
	void pushL(T key, node*& head) {
		node* new_node = new node;
		new_node->key = key;
		new_node->prev = NULL;
		new_node->next = head;
		
		if (head != NULL) {
			(head)->prev = new_node;
		}
		
		head = new_node;
	
	}
		
	node* searchL(T key, node* head) {
		if (head == NULL) return NULL;
		if (head->key == key) return head;
		node* current = head->next;
		while (current != NULL) {
			if (current->key == key)
				return current;
			current = current->next;
		}
		return NULL;
	}
	
	void deleteL(T key, node*& head) {
		node* del = searchL(key, head);
		if (head == NULL || del == NULL)
			return;
		
		if (head == del)
			head = del->next;
			
		if (del->next != NULL)
			del->next->prev = del->prev;
		
		if (del->prev != NULL)
			del->prev->next = del->next;
			
		delete del;
	}
	
	node** heads;
	
public:
    ChainedHash(int n) {
    	if (n >= 5)
    		m = n / 5;
    	else m = 1;
    	heads = new node*[m];
    	for (int i = 0; i < m; ++i)
    		heads[i] = NULL;
    }
    
    int hash(T k) {
	    return k % m;    
	}
	  
    void insert(T key) {
    	pushL(key, heads[hash(key)]);  
    }
    
    void search(T key) {
    	int s;
    	if (searchL(key, heads[hash(key)]) != NULL) {
    		s = searchL(key, heads[hash(key)])->key;
    		std::cout << "\n" << s; }
    	else std::cout << "no";
    	
    }
    
    void del(T key) {
    	deleteL(key, heads[hash(key)]);
    }

};

int main() {
	int n;
    std::cin >> n;
    ChainedHash<int> hTable(n);
    for (int i = 0; i < n; ++i) {
       int x; 
       x = i;
       //std::cin >> x;
       hTable.insert(x);    
    }
    hTable.search(11500);
    hTable.del(11500);
    hTable.search(11500);
	return 0;
}