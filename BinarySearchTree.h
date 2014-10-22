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

private:
	struct Node{
		T data;
		Node *lchild;
		Node *rchild;
	};
};



#include "detail_header/bstImpl.h"

#endif /* BINARYSEARCHTREE_H_ */
