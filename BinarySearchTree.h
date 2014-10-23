/*
 * BinarySearchTree.h
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <algorithm>
#include <iostream>
#include <map>

template <typename T, typename Comp = std::less<T> >
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& bst);
	BinarySearchTree(const T* beg, const T* end);
	~BinarySearchTree();
	const BinarySearchTree& operator=(const BinarySearchTree& bst);


	void insert(const T& elem);
	void remove (const T& elem);
	void clear();

	const T& findMax()const;
	const T& findMin()const;
	size_t size()const;

	bool isEmpty()const;
	bool contains(const T& elem)const;
	void print(std::ostream& os = std::cout);
	void printAsTree(std::ostream & os = std::cout);

private:
	struct Node{
		T data;
		Node *lchild;
		Node *rchild;
		Node(const T& value, Node* l, Node* r):data(value), lchild(l), rchild(r){

		}
	};

	struct LevelQueue{
		Node* nd;
		size_t level;
		LevelQueue(Node* node, size_t l):nd(node), level(l){

		}
	};

	Node* root;
	Comp cmp;
	bool contains(Node* root, const T& elem)const;
	void insert(Node* &root, const T& elem);
	void remove(Node* &root, const T& elem);
	void print(Node* root, std::ostream& os);
	void printAsTree(Node* root, std::ostream& os);

	size_t size(Node* root)const;
	void clear(Node* &root);
	const T& findMax(Node* root)const;
};



#include "detail_header/bstImpl.h"

#endif /* BINARYSEARCHTREE_H_ */
