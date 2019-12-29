# Table of contents
- [Overview](#overview)
  - [What AVL-tree is?](#intro)
  - [Benefits of AVL-tree](#benefits)
- [Main features](#features)
  - [Insertion](#insert)
  - [Deletion](#delete)
- [Support features](#support)
  - [Balancing tree after inserting a new element](#balance)
  

# Overview <a name="overview"></a>

## What AVL-tree is? <a name="intro"></a>
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.

**An Example Tree that is an AVL Tree:**

![Image alt](https://github.com/zhgulden/set/raw/master/pictures/AVL-Tree1.jpg)

The above tree is AVL because differences between heights of left and right subtrees for every node is less than or equal to 1.

**An Example Tree that is NOT an AVL Tree:**

![Image alt](https://github.com/zhgulden/set/raw/master/pictures/Not-AVL1.jpg)

The above tree is not AVL because differences between heights of left and right subtrees for 8 and 18 is greater than 1.

## Benefits of AVL-tree <a name="benefits"></a>
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree (See this video lecture for proof). 

# Features <a name="features"></a>

The supported operations are:

- [void insert(const ValueType & key, Node<ValueType> **ptr, Node<ValueType> *parent = NULL)](#insert)
- [void erase(const ValueType & key, Node<ValueType> **ptr>](#insert)
- void leftBig(Node<ValueType> **vertex)
- void rightBig(Node<ValueType> **vertex)
- void leftSmall(Node<ValueType> **vertex)
- void rightSmall(Node<ValueType> **vertex)
- int getDepth(Node<ValueType> *ptr)
- void updatDepth(Node<ValueType> *ptr)
- int getBalance(Node<ValueType> *ptr)
- void makeBalancePlus(Node<ValueType> **ptr)
- void makeBalanceMinus(Node<ValueType> **ptr)
- Node <ValueType> * Set <ValueType> :: balance(Node <ValueType> * ptr)
 
## Insertion  <a name="insert"></a>
To make sure that the given tree remains AVL after every insertion, we must augment the standard BST insert operation to perform some re-balancing. Following are two basic operations that can be performed to re-balance a BST without violating the BST property **(keys(left) < key(root) < keys(right))**

1) Left Rotation
2) Right Rotation, 

which realized in [Node <ValueType> * Set <ValueType> :: balance(Node <ValueType> * ptr)](#balance)

```
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
```
### Examples:
**Example 1:**

![Image alt](https://github.com/zhgulden/set/raw/master/pictures/AVL-Insertion1-1.jpg)

**Example 2:**

![Image alt](https://github.com/zhgulden/set/raw/master/pictures/AVL_Insertion_3-1.jpg)

## Deletion  <a name="delete"></a>
To make sure that the given tree remains AVL after every deletion, we must augment the standard BST delete operation to perform some re-balancing. Following are two basic operations that can be performed to re-balance a BST without violating the BST property **(keys(left) < key(root) < keys(right))**

1) Left Rotation
2) Right Rotation

which realized in [Node <ValueType> * Set <ValueType> :: balance(Node <ValueType> * ptr)](#balance)
  
```
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
````
### Example:
![Image alt](https://github.com/zhgulden/set/raw/master/pictures/AVL_TREE_DELETION.jpg)
![Image alt](https://github.com/zhgulden/set/raw/master/pictures/AVL_deletion.jpg)

## Balancing tree after inserting a new element  <a name="balance"></a>

# Files



