// 2 reverse string

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>
/*
char* reverse(char* str) {
	int size = strlen(str);
	int i = 0;
	int j = size - 1;
	while (i < j) {
		std::swap(str[i], str[j]);
		++i;
		--j;
	}
	return str;

}

int main() {
	char str[] = "abcdef";
	std::cout << reverse(str);
	return 0;
}*/


// 3
/*
bool permutation(const char* str1, const char* str2) {
	int size1 = strlen(str1);
	int size2 = strlen(str2);
	
	if (size1 != size2) return false;
	
	int* letters = new int[256];
	for (int i = 0; i < size1; ++i)
		letters[i] = 0;
	
	for (int i = 0; i < size1; ++i)
		letters[int(str1[i])] += 1;
	
	for (int i = 0; i < size2; ++i) {
		int c = int(str2[i]);
		if (--letters[c] < 0)
			return false;
	}
	
	return true;
	
}

int main() {
	char str1[] = "dog";
	char str2[] = "god";
	
	std::cout << permutation(str1, str2);
	
	return 0;
}*/

// 4
/*
bool spaceChange(char* str, int real_size) {
	int size = strlen(str);
	int space_count = 0;
	for (int i = 0; i < real_size; ++i)
		if (str[i] == ' ') {
			space_count++;
		}
	
	int new_size = real_size + 2 * space_count;
	
	if (size < new_size) {std::cout << "no space;"; return false; }
	
	str[new_size] = '\n';
	for (int i = real_size - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			str[new_size - 1] = '0';
			str[new_size - 2] = '2';
			str[new_size - 3] = '%';
			new_size -= 3;
		} else {
			str[new_size - 1] = str[i];
			new_size--;
		}
	}
	return true;
	
}

int main() {
	char str[] = "d 2  3aaaaaaa";
	spaceChange(str, 6);
	std::cout << str;
	return 0;
}
*/


// 2.1
/*
class LinkedList {
private:
	struct node {
		int key;
		node* next;
	};
node* head;
public:
	LinkedList() {
		head = NULL;
	}
	
	void insert(int key) {
		node* new_node = new node;
		new_node->key = key;
		new_node->next = NULL;
		if (head == NULL) {
			head = new_node;
			return;
		}
		new_node->next = head;
		head = new_node;	
	}
	
	void del() {
		node* current = head;
		std::unordered_map<int, bool> map;
		node* prev = NULL;
		while (current != NULL) {
			if (map.find(current->key) != map.end()) {
				prev->next = current->next;
			} else {
				std::cout << current->key << "\n";
				map[current->key] = true;
				prev = current;
			}
			current = current->next;
		}
	}
	
	void print() {
		node* current = head;
		while (current != NULL) {
			std::cout << current->key << " ";
			current = current->next;
		}	
	}
};


int main() {
	LinkedList ll;
	ll.insert(6);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.del();
	ll.print();
	return 0;
} */

// 2.2 kth last element in linked list

/*
class LinkedList {
private:
	struct node {
		int key;
		node* next;
	};
node* head;
public:
	LinkedList() {
		head = NULL;
	}
	
	void insert(int key) {
		node* new_node = new node;
		new_node->key = key;
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
			std::cout << current->key << " ";
			current = current->next;
		}	
	}
	
	node* kthLast(int k, node* current, int& i) {
		if (current == NULL)
			return NULL;
			
		node* kth = kthLast(k, current->next, i);
		++i;
		if (i == k) {
			return current;
		} 
			
		return kth;	
	}
	
	node* getHead() {
		return head;
	}
	
	node* kth_iter(int k) {
		node * p1 = head, *p2 = head;
		int count = 0;
		while (p1 != NULL && count < k) {
			p1 = p1->next;
			++count;
		}
		if (p1 == NULL) return NULL;
		while (p1->next != NULL) {
			p2 = p2->next;
			p1 = p1->next;
		}
		return p2;
	}
	
	void del_node(node* nod) {
		if (nod == NULL) return;
		node* next_node = nod->next;
		nod->key = next_node->key;
		nod->next = next_node->next;
		delete(next_node);
	}
};

int main () {
	LinkedList ll;
	ll.insert(6);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	int k = 0;
	std::cout << ll.kthLast(4, ll.getHead(), k)->key;
	std::cout << std::endl <<  ll.kth_iter(2)->key;
		
}*/

// 3.4 ханойские башни

/*

class Tower {
private:
	std::stack<int> disks;
	int index;
public:
	Tower(int i) {
		index = i;
	}
	
	Tower& operator = (Tower* t) {
		index = t->index;
		disks = t->disks;
		return *this;
	}

	void add(int d) {
		if (!disks.empty() && disks.top() <= d)
			std::cout << "error moving";
		else disks.push(d);
	}
	
	void moveTopTo(Tower t) {
		int top = disks.top();
		disks.pop();
		t.add(top);
	}
	
	void movedisks(int n, Tower dest, Tower buff) {
		if (n > 0) {
			movedisks(n - 1, buff, dest);
			moveTopTo(dest);
			buff.movedisks(n - 1, dest, *this);
		}
	}
	
	void print() {
		while (!disks.empty()) {
			std::cout << disks.top() << "  ";
			disks.pop();
		}
	}

};

int main() {
	int n = 3;
	Tower t1(1);
	Tower t2(2);
	Tower t3(3);
	
	for (int i = n - 1; i >= 0; --i)
		t1.add(i);
	
	t1.movedisks(n, t3, t2);
	t3.print();
				
	
	return 0;
}*/


/*
template <class T>
class BST {
private:
	struct node {
		T key;
		node* parent;
		node* left;
		node* right;
		node(T k) {
			this->key = k;
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
		}
	};
public:
	node* root;
	
	BST() {
		this->root = NULL;
	}
	
	void tree_insert(T key) {
		node* y = NULL;
		node* x = this->root;
		
		while (x != NULL) {
			y = x;
			if (key < x->key) {
				x = x->left;
			} else {
				x = x->right;
			}
		}
		
		node* z = new node(key);
		z->parent = y;
		if (y == NULL) {
			this->root = z;
		} else if (key < y->key) {
			y->left = z;
		} else {
			y->right = z;
		}
	}
	
	node* minimum(node* leaf) {
		if (leaf == NULL) return NULL;
		while (leaf->left != NULL) {
			leaf = leaf->left;
		}
		return leaf;
	}
	
	node* maximum(node* leaf) {
		if (leaf == NULL) return NULL;
		while (leaf->right != NULL) {
			leaf = leaf->right;
		}
		return leaf;
	}
	
	node* successor(node* leaf) {
		if (leaf == NULL) return NULL;
		if (leaf->right != NULL)
			return this->minimum(leaf->right);
		node* y = leaf->parent;
		while (y != NULL && leaf == y->right) {
			leaf = y;
			y = y->parent;
		}
		return y;
	}
	
	node* predecessor(node* leaf) {
	    if (leaf == NULL) return NULL;
		if (leaf->left != NULL)
			return this->maximum(leaf->left);
		node* y = leaf->parent;
		while (y != NULL && leaf == y->left) {
			leaf = y;
			y = y->parent;
		}
		return y;		
	}
	
	node* rec_search(node* leaf, T key) {
		if (leaf != NULL && leaf->key == key)
			return leaf;
		if (key < leaf->key) {
			return rec_search(leaf->left, key);
		} else {
			return rec_search(leaf->right, key);
		}	
	}
	
	node* iter_search(node* leaf, T key) {
		while (leaf != NULL && leaf->key != key) {
			if (key < leaf->key) {
				leaf = leaf->left;
			} else {
				leaf = leaf->right;
			}
		}
		return leaf;
	}
	
	void transplant(node* u, node* v) {
		if (u->parent == NULL) this->root = v;
		else if (u == u->parent->left) {
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		if (v != NULL) {
			v->parent = u->parent;
		}
	}
	
	void tree_delete(node* z) {
		if (z == NULL) return;
		if (z->left == NULL) {
			this->transplant(z, z->right);
		} else if (z->right == NULL) {
			this->transplant(z, z->left);
		} else {
			node* y = this->minimum(z->right);
			if (y->parent != z) {
				this->transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			this->transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
		}
	}
	
	void inorder_tree_walk(node* leaf) {
		if (leaf != NULL) {
			inorder_tree_walk(leaf->left);
			std::cout << leaf->key << " ";
			inorder_tree_walk(leaf->right);
		}
	}
	
	int checkHeight(node* leaf) {
		if (leaf == NULL)
			return 0;
		
		int l_height = checkHeight(leaf->left);
		if (l_height == -1) return -1;
		int r_height = checkHeight(leaf->right);
		if (r_height == -1) return -1;
		
		int diff = abs(l_height - r_height);
		if (diff > 1) return - 1;
		else return 1 + std::max(l_height, r_height);
		
	}
	
	bool isBalanced() {
		if (checkHeight(root) == -1) return false;
		else return true;
	}
	
};

int main() {
	int n;
	std::cin >> n;
	BST<int> bst;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		bst.tree_insert(x);
	}
	std::cout << bst.isBalanced();
	return 0;
} */

// BFS

class Graph
{
    int V;    // No. of vertices
    std::list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    void DFS(int s);
    void DFSutil(int, bool*);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
		visited[i] = false;
		
	std::list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	std::list<int>::iterator i;
	
	while(!queue.empty()) {
		s = queue.front();
		std::cout << s << " ";
		queue.pop_front();
		
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	
}
	
	void Graph::DFSutil(int v, bool* visited) {
	
		visited[v] = true;
		std::cout << v << " ";
		std::list<int>::iterator i;
		
		for (i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (!visited[*i]) {
				DFSutil(*i, visited);	
			}
		}
	
	}
		
	void Graph::DFS(int s) {
		bool* visited = new bool[V];
		for (int i = 0; i < V; ++i)
			visited[i] = false;
		DFSutil(s, visited);		
	}

int main() {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    std::cout << "'nFollowing is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
}

