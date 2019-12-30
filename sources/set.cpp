#include <iostream>
#include <vector>
#include <set>
#include <cassert>

template <class ValueType>

struct Node {
    ValueType key;
    Node * left;
    Node * right;
    int depth;
};

template <class ValueType>

class Set {
    size_t size_;
    Node <ValueType> *root;
    Node <ValueType> * rotateleft(Node <ValueType> * ptr);
    Node <ValueType> * rotateright(Node <ValueType> * ptr);
    Node <ValueType> * find_min(Node <ValueType> * ptr);
    Node <ValueType> * erase_min(Node <ValueType> * ptr);
    int getDepth (Node <ValueType> * ptr);
    void updateDepth (Node <ValueType> * ptr);
    int getBalance (Node <ValueType> * ptr);
    Node <ValueType> * balance(Node <ValueType> * ptr);
    Node <ValueType> * insert (const ValueType & key, Node <ValueType> * parent);
    Node <ValueType> * erase (const ValueType & key, Node <ValueType> * ptr);
    void copy_set(Node <ValueType> * ptr);
    void clear (Node <ValueType> * ptr);
    void print(Node <ValueType> * ptr);
    bool find(Node <ValueType> * ptr, const ValueType & key);
    public:
        Set() {
            root = NULL;
            size_ = 0;
        }
        Set (const Set <ValueType> & source);
        size_t size () const;
        bool empty () const;
        bool find(const ValueType & key);
        void insert (const ValueType & key);
        void erase (const ValueType & key);
        void print();
        void clear();
        void print_debug();
        ~Set () {
            clear();
        }
};

template <class ValueType>

bool Set <ValueType> :: find(Node <ValueType> * ptr, const ValueType & key) {
    if(ptr == NULL) {
        return 0;
    }
    if (ptr -> key == key) {
        return 1;
    } else if (ptr -> key > key) {
        return find(ptr -> left, key);
    }
    return find(ptr -> right, key);
}

template <class ValueType>

bool Set <ValueType> :: find(const ValueType & key) {
    return find(root, key);
}

template <class ValueType>

void Set <ValueType> :: print(Node <ValueType> * ptr) {
    if(ptr != NULL) {
        print(ptr -> left);
        std :: cout << ptr -> key << ' ';
        print(ptr -> right);
    }
}

template <class ValueType>

void Set <ValueType> :: print() {
    print(root);
}

template <class ValueType>

void Set <ValueType> :: copy_set (Node <ValueType> * ptr) {
    if(ptr != NULL) {
        insert(ptr -> key);
        copy_set(ptr -> left);
        copy_set(ptr -> right);
    }
}

template <class ValueType>

Set <ValueType> :: Set (const Set <ValueType> & source) {
    root = NULL;
    copy_set(source.root);
}

template <class ValueType>

size_t Set <ValueType> :: size() const {
    return size_;
}

template <class ValueType>

void Set <ValueType> :: clear() {
    clear(root); 
}

template <class ValueType>

void Set <ValueType> :: clear (Node <ValueType> * ptr) {
    if(ptr != NULL) {
        Node <ValueType> * l_tree = ptr -> left;
        Node <ValueType> * r_tree = ptr -> right;
        delete ptr;
        clear(l_tree);
        clear(r_tree);
    }
    root = NULL;
}

template <class ValueType>

void Set <ValueType> :: erase(const ValueType & key) {
    root = erase(key, root);
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: erase (const ValueType & key, Node <ValueType> * ptr) {
    if(ptr == NULL) {
        return NULL;
    }
	if (key < ptr -> key) {
		ptr -> left = erase(key, ptr -> left);
    } else if (key > ptr -> key) {
		ptr -> right = erase(key, ptr -> right);	
    } else {
        Node <ValueType> * l_tree = ptr -> left;
		Node <ValueType> * r_tree = ptr -> right;
		delete ptr;
		if (r_tree == NULL) {
		    return l_tree;
        }
		Node <ValueType> * min_node = find_min(r_tree);
		min_node -> right = erase_min(r_tree);
		min_node -> left = l_tree;
		return balance(min_node);
    }
}

template <class ValueType>

bool Set <ValueType> :: empty () const {
    if (root == NULL) {
        return 1;
    }
    return 0;
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: erase_min(Node <ValueType> * ptr) { 
    if (ptr -> left == NULL) {
        return ptr -> right;
    }
    ptr -> left = erase_min(ptr -> left);
    return balance(ptr);
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: find_min(Node <ValueType> * ptr) {
    if (ptr -> left != NULL) {
        return find_min(ptr -> left);
    }
    return ptr;
}


template <class ValueType>

Node <ValueType> * Set <ValueType> :: rotateright(Node <ValueType> * ptr) {
	Node <ValueType> * tmp = ptr->left;
	ptr -> left = ptr->right;
	tmp -> right = ptr;
	updateDepth(ptr);
	updateDepth(tmp);
	return tmp;
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: rotateleft(Node <ValueType> * ptr) {
    Node <ValueType> * tmp = ptr -> right;
	ptr -> right = tmp -> left;
	tmp -> left = ptr;
	updateDepth(ptr);
	updateDepth(tmp);
	return tmp;
}

template <class ValueType>

int Set <ValueType> :: getBalance (Node <ValueType> * ptr) {
    return getDepth(ptr -> right) - getDepth(ptr -> left);
}

template <class ValueType>

int Set<ValueType>::getDepth(Node<ValueType> *ptr) {
    if (ptr == nullptr)
        return 0;
    return ptr->depth;
}

template <class ValueType>

void Set <ValueType> :: insert(const ValueType & key) {
    ++size_;
    root = insert(key, root);
}

template <class ValueType>

void Set <ValueType> :: updateDepth (Node <ValueType> * ptr) {
    if(getDepth(ptr -> left) > getDepth(ptr -> right)) {
        ptr -> depth = getDepth(ptr -> left) + 1;
    } else {
        ptr -> depth = getDepth(ptr -> right) + 1;
    }
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: insert(const ValueType & key, Node <ValueType> * parent) {
    if (parent == NULL) {
        Node <ValueType> * new_el = new Node <ValueType>;
        new_el -> key = key;
        new_el -> depth = 1;
        return new_el;
    } else {
        if(parent -> key == key) {
            return parent;
        }
        if (key < parent -> key) {
            parent -> left = insert(key, parent -> left);
        } else {
            parent -> right = insert(key, parent -> right);
        }
    }
    return balance(parent);
}

template <class ValueType>

Node <ValueType> * Set <ValueType> :: balance(Node <ValueType> * ptr) {
    updateDepth(ptr);
    if(getBalance(ptr) == 2) {
		if(getBalance(ptr -> right) < 0) {
			ptr -> right = rotateright(ptr -> right);
        }
		return rotateleft(ptr);
	}
	if(getBalance(ptr) == -2) {
		if (getBalance(ptr -> left) > 0)
			ptr -> left = rotateleft(ptr -> left);
		return rotateright(ptr);
	}
	return ptr;
}

template <class ValueType>

void Set <ValueType> :: print_debug() {
    std :: vector <Node <ValueType>*> one, two;
    int hmax = 6, width = 1 << hmax ;
    one.push_back(root);
    for (int level = 0; level < hmax; ++level) {
        std :: string filler (width - 1 , ' ' );
        for (auto elem : one) {
            if (elem) {
                std :: cout << filler << elem -> key << " (" << elem -> depth << ')' << filler;
                two.push_back (elem -> left);
                two.push_back (elem -> right);
            } else {
                std :: cout << filler << " --" << filler;
                two.push_back(nullptr);
                two.push_back(nullptr);
            }
        }
        std :: cout << std :: endl;
        one = two;
        two.clear();
        width /= 2;
    }
}

int main() {
    std :: set <int> stlset;
    std::set<int>::iterator it;
    Set <int> new_set;
    int n, tmp;
    n = 100000;
    for(int i = 1; i <= n; i++) {
        std :: cin >> tmp;
        new_set.insert(tmp);
        stlset.insert(tmp);
    }
	for (int i = 1; i <= n; i++) {
        std :: cin >> tmp;
		bool a = new_set.find(tmp) != 0;
		bool b = stlset.find(tmp) != stlset.end();
		assert(a == b);
	}
	std :: cout << "tested" << std :: endl;
    return 0;
}
