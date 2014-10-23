/*
 * bstImpl.h
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */

#ifndef BSTIMPL_H_
#define BSTIMPL_H_
#include <queue>

template<typename T, typename Comp >
inline BinarySearchTree<T, Comp>::BinarySearchTree():root(NULL){
}

template<typename T, typename Comp>
inline BinarySearchTree<T, Comp>::BinarySearchTree(
		const BinarySearchTree& bst) {
	root = bst.root;
	cmp = bst.cmp;
}

template<typename T, typename Comp >
inline BinarySearchTree<T, Comp>::~BinarySearchTree() {
	clear();
	root = NULL;
}

template<typename T, typename Comp >
const BinarySearchTree<T, Comp>& BinarySearchTree<T, Comp>::operator=(const BinarySearchTree& bst) {
	root = bst.root;
	cmp = bst.cmp;
	return *this;
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(const T& elem) {
	return insert(root, elem);

}



template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(Node* &root, const T& elem) {
	if(NULL == root){
		root = new Node(elem, NULL, NULL);
		return ;
	}

	if(elem <= root->data){
		return insert(root->lchild, elem);
	}
	else{
		return insert(root->rchild, elem);
	}
	return ;
}

template<typename T, typename Comp>
bool BinarySearchTree<T, Comp>::contains(Node* root, const T& elem) const {
	if(NULL == root){
		return false;
	}

	if(elem == root->data){
		return true;
	}
	else if(elem < root->data){
		return contains(root->lchild, elem);
	}
	else{
		return contains(root->rchild, elem);
	}
	return false;
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::print(std::ostream& os){
	print(root, os);
	os << "\n";
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::printAsTree(std::ostream& os){
	printAsTree(root, os);
	os << "\n";
}

template<typename T, typename Comp>
BinarySearchTree<T, Comp>::BinarySearchTree(const T* beg, const T* end): root(NULL){
	for(const T* pos = beg; pos != end; pos++){
		insert(*pos);
	}
}
template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::print(Node* root, std::ostream& os){
	if(NULL == root){
		return ;
	}
	os << root->data << " ";
	print(root->lchild, os);
	print(root->rchild, os);
}

template<typename T, typename Comp>
inline void BinarySearchTree<T, Comp>::remove(const T& elem) {
	return remove(root, elem);
}

template<typename T, typename Comp>
inline void BinarySearchTree<T, Comp>::clear() {
	return clear(root);
}

template<typename T, typename Comp>
inline const T& BinarySearchTree<T, Comp>::findMax() const {
}

template<typename T, typename Comp>
inline const T& BinarySearchTree<T, Comp>::findMin() const {
}

template<typename T, typename Comp>
inline size_t BinarySearchTree<T, Comp>::size() const {
}

template<typename T, typename Comp>
inline bool BinarySearchTree<T, Comp>::isEmpty() const {
	return NULL == root;
}

template<typename T, typename Comp>
bool BinarySearchTree<T, Comp>::contains(const T& elem) const {
	return contains(root, elem);
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::remove(Node*& root, const T& elem) {
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::printAsTree(Node* root, std::ostream& os){
	if(NULL == root){
		std::cout << "nil" << std::endl;
	}

	size_t level = 0, pre_level = 0;
	LevelQueue lq(root,level);
	std::queue<LevelQueue> que;
	que.push(lq);

	while(!que.empty()){
		LevelQueue& top = que.front();
		Node *node = top.nd;
		if(pre_level < top.level){
			os << "\n";
			pre_level = top.level;
		}
		os << node->data << "   ";
		if(node->lchild){
			que.push(LevelQueue(node->lchild, top.level+1));
		}
		if (node->rchild){
			que.push(LevelQueue(node->rchild, top.level+1));
		}
		que.pop();
	}
	return ;

}


template<typename T, typename Comp>
size_t BinarySearchTree<T, Comp>::size(Node* root) const {
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::clear(Node*& root) {
	if(NULL == root){
		return ;
	}
	clear(root->lchild);
	clear(root->rchild);
	if(NULL == root->lchild && NULL == root->rchild){
		delete root;
		root = NULL;
	}
	return ;
}

template<typename T, typename Comp>
const T& BinarySearchTree<T, Comp>::findMax(Node* root) const {
}

#endif /* BSTIMPL_H_ */
