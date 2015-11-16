#include <iostream>

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
	bst.inorder_tree_walk(bst.root);
	std::cout << std::endl << bst.rec_search(bst.root, 3);
	std::cout << std::endl << bst.iter_search(bst.root, 3);
	std::cout <<  std::endl << bst.root->key;
	std::cout << std::endl << bst.successor(bst.iter_search(bst.root, 1));
	std::cout << std::endl << bst.predecessor(bst.iter_search(bst.root, 1));
	bst.tree_delete(bst.iter_search(bst.root, 3));
	std::cout << std::endl;
	bst.inorder_tree_walk(bst.root);

	return 0;
}