/*
 * avlImpl.h
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */

#ifndef AVLIMPL_H_
#define AVLIMPL_H_
#include <iostream>
#include <algorithm>
#include <queue>

template<typename T>
inline AvlTree<T>::AvlTree(): len(0), proot(NULL){
}

template<typename T>
inline AvlTree<T>::AvlTree(const AvlTree& bst):len(bst.len), proot(bst.proot){
}

template<typename T>
inline AvlTree<T>::AvlTree(const T* beg, const T* end): len(0), proot(NULL){
}



template<typename T>
inline bool AvlTree<T>::contains(AvlNode<T>* root, const T& elem) const {
	if(NULL == root){
		return false;
	}

	if(elem == root->element){
		return true;
	}
	else if(elem < root->element){
		return contains(root->lchild, elem);
	}
	else{
		return contains(root->rchild, elem);
	}
	return false;
}

template<typename T>
inline void AvlTree<T>::insert(AvlNode<T>* &root, const T& x) {
	if(NULL == root){
		root = new AvlNode<T>(x, NULL, NULL);
		return ;
	}
	else if (x < root->element){
		insert(root->lchild, x);
		if(height(root->lchild) - height(root->rchild) == 2){
			if(x < root->lchild->element){
				singleRotateLeftChild(root);
			}
			else{
				doubleRotateLeftChild(root);
			}
		}
	}
	else if ( x > root->element){
		insert(root->rchild, x);
		if(height(root->rchild) - height(root->lchild) == 2){
			if(x > root->rchild->element){
				singleRotateRightChild(root);
			}
			else{
				doubleRotateRightChild(root);
			}
		}
	}
	else{
		;
	}
	root->height = std::max(height(root->lchild), height(root->rchild)) + 1;
}


template<typename T>
inline AvlTree<T>::~AvlTree() {
}


template<typename T>
inline void AvlTree<T>::insert(const T& elem) {
	return insert(proot, elem);
}


template<typename T>
inline bool AvlTree<T>::contains(const T& elem) const {
	return contains(proot, elem);
}

template<typename T>
inline void AvlTree<T>::print(std::ostream& os) {
	return print(proot, os);
}

template<typename T>
inline void AvlTree<T>::printAsTree(std::ostream& os) {
	return printAsTree(proot, os);
}


template<typename T>
inline void AvlTree<T>::singleRotateLeftChild(AvlNode<T>*& k2) {
	if(k2 == NULL){
		return ;
	}
	AvlNode<T>* k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2->height = std::max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = std::max(height(k1->lchild), k2->height) + 1;
	k2 = k1;
}

template<typename T>
inline void AvlTree<T>::singleRotateRightChild(AvlNode<T>*& k2) {
	if(k2 == NULL){
		return ;
	}
	AvlNode<T>* k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;

	k2->height = std::max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = std::max(height(k1->lchild), height(k1->rchild)) + 1;
	k2 = k1;
}

template<typename T>
inline void AvlTree<T>::doubleRotateLeftChild(AvlNode<T>*& root) {
	singleRotateRightChild(root->lchild);
	singleRotateLeftChild(root);
}

template<typename T>
inline void AvlTree<T>::doubleRotateRightChild(AvlNode<T>*& root) {
	singleRotateLeftChild(root->rchild);
	singleRotateRightChild(root);
}

template<typename T>
size_t AvlTree<T>::hight()const{
	return calHeight(proot);
}

template<typename T>
inline void AvlTree<T>::fillWithArray(const std::vector<T>& v) {
	size_t len = v.size();
	for(size_t i = 0; i < len; i++){
		insert(v[i]);
	}
}



template<typename T>
inline void AvlTree<T>::printToDot(std::ostream& os) {
	return printToDot(proot, os);
}

template<typename T>
size_t AvlTree<T>::calHeight(AvlNode<T>* root) const {
	if(NULL == root){
		return 0;
	}
	return std::max(calHeight(root->lchild), calHeight(root->rchild)) + 1;
}


template<typename T>
inline void AvlTree<T>::print(AvlNode<T>* root, std::ostream& os) {
	if(NULL == root){
		return ;
	}
	os << root->element << " ";
	print(root->lchild, os);
	print(root->rchild, os);
}
template<typename T>
struct NodeType{
	AvlNode<T>* node;
	int depth;
	NodeType(AvlNode<T>* n, int d): node(n), depth(d){

	}
};

template<typename T>
void AvlTree<T>::printAsTree(AvlNode<T>* root, std::ostream& os){

	if(NULL == root){
		return ;
	}
	std::queue<NodeType<T> > nodeQueue;
	int depth = -1;
	nodeQueue.push(NodeType<T>(root, 0));
	while(!nodeQueue.empty()){
		NodeType<T> nt = nodeQueue.front();
		AvlNode<T>* node = nt.node;
		if(nt.depth > depth){
			os << "\n";
			depth = nt.depth;
		}
		os << node->element << "\t";
		if(node->lchild){
			nodeQueue.push(NodeType<T>(node->lchild, nt.depth+1));
		}
		if(node->rchild){
			nodeQueue.push(NodeType<T>(node->rchild, nt.depth+1));
		}
		nodeQueue.pop();
	}
}

template<typename T>
inline void AvlTree<T>::printToDot(const AvlNode<T>* root, std::ostream& os) const {
	//std::queue<AvlNode<T>* > que;
	if(NULL == root){
		return ;
	}
	os << "\ndigraph G{\n";
	os << "\tlabel = " << "\"binary_search_tree\"";
	os << "\tstyle = \"dashed\";\n";
	os << "\tcolor = purple;\n";

	std::vector<const AvlNode<T>* > nodeList;
	size_t ip = 0, ichild = 0;
	nodeList.push_back(root);
	const AvlNode<T>* pNode = root;
	while(ip < nodeList.size()){
		pNode = nodeList[ip];
		os << "\tNode" << ip << " [ label = \"" << pNode->element << " \"];\n";
		os << "\tNode" << ip << "->" << "{ ";
		if(pNode->lchild){
			os << "Node" << ++ichild << " ";
			nodeList.push_back(pNode->lchild);
		}
		if(pNode->rchild){
			os << "Node" << ++ichild << " " ;
			nodeList.push_back(pNode->rchild);
		}
		os << "}" << std::endl;
		ip++;
	}
	os << "}" << std::endl;
	return ;
}


#endif /* AVLIMPL_H_ */
