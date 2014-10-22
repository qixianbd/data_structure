/*
 * BinarySearchTree.h
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <algorithm>
#include <map>

template <typename T, typename Comp = std::less<T> >
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& bst);
	~BinarySearchTree();
	const BinarySearchTree& operator=(const BinarySearchTree& bst);

	void insert(const T& elem);
	bool isEmpty()const{
		return NULL == root;
	}
	bool contains(const T& elem)const{
		return contains(elem, root);
	}

private:
	struct Node{
		T data;
		Node *lchild;
		Node *rchild;
		Node(const T& value, const Node* l, const Node* r):data(value), lchild(l), rchild(r){

		}
	};
	Node* root;
	Comp cmp;
	bool contains(const T& elem, Node* root)const;
	void insert(const T& elem, Node* root);
};



#include "detail_header/bstImpl.h"

#endif /* BINARYSEARCHTREE_H_ */
