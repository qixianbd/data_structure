/*
 * bstImpl.h
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */

#ifndef BSTIMPL_H_
#define BSTIMPL_H_
#include <queue>
#include <stdexcept>

template<typename T, typename Comp >
inline BinarySearchTree<T, Comp>::BinarySearchTree():proot(NULL), len(0){
}

template<typename T, typename Comp>
inline BinarySearchTree<T, Comp>::BinarySearchTree(
		const BinarySearchTree& bst):proot(NULL),cmp(bst.cmp), len(bst.len){
	proot = clone(bst.proot);
}

template<typename T, typename Comp >
inline BinarySearchTree<T, Comp>::~BinarySearchTree() {
	clear();
	proot = NULL;
	len = 0;
}

template<typename T, typename Comp >
const BinarySearchTree<T, Comp>& BinarySearchTree<T, Comp>::operator=(const BinarySearchTree& bst) {
	clear();
	clone(bst);
	len = bst.len;
	cmp = bst.cmp;
	return *this;
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(const T& elem) {
	return insert(proot, elem);
}



template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(Node* &root, const T& elem) {
	if(NULL == root){
		root = new Node(elem, NULL, NULL);
		len++;
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
	print(proot, os);
	os << "\n";
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::printAsTree(std::ostream& os){
	printAsTree(proot, os);
	os << "\n";
}

template<typename T, typename Comp>
BinarySearchTree<T, Comp>::BinarySearchTree(const T* beg, const T* end): proot(NULL){
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
	return remove(proot, elem);
}

template<typename T, typename Comp>
inline void BinarySearchTree<T, Comp>::clear() {
	clear(proot);
	proot = NULL;
	len = 0;
	return;
}

template<typename T, typename Comp>
inline const T& BinarySearchTree<T, Comp>::findMax() const {
	if(len == 0){
		throw std::out_of_range("len = 0");
	}
	return findMax(proot)->data;
}

template<typename T, typename Comp>
inline const T& BinarySearchTree<T, Comp>::findMin() const {
	if(len == 0){
		throw std::out_of_range("len = 0");
	}
	return findMin(proot)->data;
}

template<typename T, typename Comp>
inline size_t BinarySearchTree<T, Comp>::size() const {
	return len;
}

template<typename T, typename Comp>
inline bool BinarySearchTree<T, Comp>::isEmpty() const {
	return NULL == proot;
}

template<typename T, typename Comp>
bool BinarySearchTree<T, Comp>::contains(const T& elem) const {
	return contains(proot, elem);
}

//template<typename T, typename Comp>
//BinarySearchTree<T, Comp>::Node* BinarySearchTree<T, Comp>::findMin(BinarySearchTree<T, Comp>::Node* root) const {
//	if(root == NULL){
//		return NULL;
//	}
//	if(root->lchild == NULL){
//		return root;
//	}
//	else{
//		Node* pos = root;
//		while(pos->lchild != NULL){
//			pos = pos->lchild;
//		}
//		return pos;
//	}
//}
//
//template<typename T, typename Comp>
//BinarySearchTree<T, Comp>::Node* BinarySearchTree<T, Comp>::findMax(BinarySearchTree<T, Comp>::Node* root) const {
//	if(root == NULL){
//		return NULL;
//	}
//	if(root->rchild == NULL){
//		return root;
//	}
//	else{
//		Node* pos = root;
//		while(pos->rchild != NULL){
//			pos = pos->rchild;
//		}
//		return pos;
//	}
//}


template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::remove(Node*& root, const T& elem) {
	if(NULL == root){
		return ;
	}
	if(elem == root->data){
		if(root->rchild == NULL && root->lchild == NULL){
			delete root;
			root = NULL;
			len--;
			return ;
		}
		else if(root->rchild == NULL){
			Node* pos = root;
			root = root->lchild;
			std::cout << "root->data = " << root->data << ", root->lchild = " << root->lchild << ",root->rchild = " << root->rchild << std::endl;

			delete pos;
			std::cout << "root->data = " << root->data << ", root->lchild = " << root->lchild << ",root->rchild = " << root->rchild << std::endl;

			return ;
		}
		else{
			Node *pos = findMin(root->rchild);
			T temp = pos->data;
			remove(root->rchild, pos->data);
			root->data = temp;

			return ;
		}

	}
	else if (elem < root->data){
		remove(root->lchild, elem);
		std::cout << "root->data = " << root->data << ", root->lchild = " << root->lchild << ",root->rchild = " << root->rchild << std::endl;
		return ;
	}
	else{
		remove(root->rchild, elem);
		std::cout << "root->data = " << root->data << ", root->lchild = " << root->lchild << ",root->rchild = " << root->rchild << std::endl;
		return ;
	}
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
	return len;
}

template<typename T, typename Comp>
inline size_t BinarySearchTree<T, Comp>::hight() const {
	return hight(proot);
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::clear(Node*& root) {
	static size_t icount = 0;
	if(NULL == root){
		return ;
	}
	clear(root->lchild);
	clear(root->rchild);
	if(NULL == root->lchild && NULL == root->rchild){
		delete root;
		icount++;
		std::cerr << "icount = " << icount << std::endl;
		root = NULL;
	}
	return ;
}



#endif /* BSTIMPL_H_ */
