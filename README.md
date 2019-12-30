# Table of contents
- [Overview](#overview)
  - [What AVL-tree is?](#intro)
  - [Benefits of AVL-tree](#benefits)
- [Features](#features)
- [Requirements](#req)
- [Compilation](#compile)
- [How to run program?](#run)

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

- void insert(const ValueType & key, Node<ValueType> **ptr, Node<ValueType> *parent = NULL)
- void erase(const ValueType & key, Node<ValueType> **ptr>
- Node <ValueType> * rotateleft(Node <ValueType> * ptr)
- void rightBig(Node<ValueType> **vertex)
- int getDepth(Node<ValueType> *ptr)
- void updatDepth(Node<ValueType> *ptr)
- int getBalance(Node<ValueType> *ptr)
- void makeBalancePlus(Node<ValueType> **ptr)
- void makeBalanceMinus(Node<ValueType> **ptr)
- Node <ValueType> * Set <ValueType> :: balance(Node <ValueType> * ptr)
 
# Requirements <a name="req"></a>
The program code was written in the C ++ programming language, therefore, to compile the code, you must install g++.
GNU C++ Compiler ( g++ ) is a compiler in Linux which is used to compile C++ programs.

`sudo apt-get update`
`sudo apt-get install g++`

# Compilation <a name="compile"></a>
`make set`

# How to run program? <a name="run"></a>
If you want to enter your oun set of input numbers, run the program as follows:`./set`
