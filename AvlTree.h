/*
 * AVLTree.h
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>

template<typename T>
struct AvlNode{
	T element;
	AvlNode *lchild;
	AvlNode *rchild;
	int height;
	AvlNode(const T& theElement, AvlNode* left, AvlNode *right, int h = 0):element(theElement), lchild(left),
			rchild(right), height(h){
	}
};
template<typename T>
class AvlTree{
public:
	AvlTree();
	AvlTree(const AvlTree& bst);
	AvlTree(const T* beg, const T* end);
	~AvlTree();
	const AvlTree& operator=(const AvlTree& bst);

	void fillWithArray(const std::vector<T>& v);
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
	void printToDot(std::ostream &os = std::cout);
	size_t hight()const;
private:
	size_t len;
	AvlNode<T> *proot;

	void singleRotateLeftChild(AvlNode<T>* &root);
	void singleRotateRightChild(AvlNode<T>* &root);

	void doubleRotateLeftChild(AvlNode<T>* &root);
	void doubleRotateRightChild(AvlNode<T>* &root);



	bool contains(AvlNode<T>* root, const T& elem)const;
	void insert(AvlNode<T>* &root, const T& elem);
	void remove(AvlNode<T>* &root, const T& elem);
	void print(AvlNode<T>* root, std::ostream& os = std::cout);
	void printAsTree(AvlNode<T>* root, std::ostream& os = std::cout);
	size_t calHeight(AvlNode<T>* root)const;
	void printToDot(const AvlNode<T>* root, std::ostream& os = std::cout)const;
};





template<typename T>
int height(const AvlNode<T>* root){
	return NULL == root ? -1 : root->height;
}



#include "detail_header/avlImpl.h"

#endif /* AVLTREE_H_ */
