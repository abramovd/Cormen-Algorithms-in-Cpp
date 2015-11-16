#include <iostream>
#include <ctime>

template <class T>
class AddressHash {
private:
	int size;
	T* table;
	int hash_base(T key) {
		return key % size;
	}
	
	int hash_base2(T key) {
		return 1 + (key % (size - 1));
	}
	
	int hash_linear(T key, int i) {
		return (hash_base(key) + i) % size;
	}
	
	int hash_squered(T key, int i) {
		int c1 = 1;
		int c2 = 1;
		return (hash_base(key) + c1 * i + c2 * i * i) % size;
	}
	
	int double_hash(T key, int i) {
		return (hash_base(key) + i * hash_base2(key)) % size;
	}
	
public:
	AddressHash() {
		size = 31;
		table = new T[size];
		for (int i = 0; i < size; ++i)
			table[i] = -1;
	}
	
	int insert(T key) {
		int i = 0;
		do {
			int j = double_hash(key, i);
			if (table[j] == -1) {
				table[j] = key;
				return j;
			} else {
				++i;
			}
		} while (i < size);
		if (i >= size) std::cout << "\nTable is full\n";	
		return -1;
	}
	
	T search(T key) {
		int i = 0;
		int j;
		do {
			j = double_hash(key, i);
			if (table[j] == key) {
				return j;
			}
			++i;
		} while (i < size && table[j] != -1);		
		return -1;
	}
	
	void print() {
		std::cout << '\n';
		for (int i = 0; i < size; ++i)
			std::cout << table[i] << "  ";
	}
	
	~AddressHash() {
		delete [] table;
	}

};

int main() {
	int n;
	std::cin >> n;
	srand(time(NULL));
	AddressHash<int> hashTable;
	int m;
	for (int i = 0; i < n; ++i) {
		m = 1 + rand() % 100;
		int j = hashTable.insert(m);
		std::cout << std::endl << m << " -> " << j << std::endl;
	}
	hashTable.print();
	std::cout << std::endl << m << " -> " << hashTable.search(m);
	return 0;
}