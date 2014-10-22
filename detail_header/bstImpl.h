/*
 * bstImpl.h
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */

#ifndef BSTIMPL_H_
#define BSTIMPL_H_


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
}

template<typename T, typename Comp >
const BinarySearchTree<T, Comp>& BinarySearchTree<T, Comp>::operator=(const BinarySearchTree& bst) {
	root = bst.root;
	cmp = bst.cmp;
	return *this;
}

template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(const T& elem) {
	return insert(elem, root);

}



template<typename T, typename Comp>
void BinarySearchTree<T, Comp>::insert(const T& elem, Node* root) {
	if(NULL == root){
		root = new Node(elem, NULL, NULL);
		return ;
	}

	if(elem <= root->data){
		return insert(elem, root->lchild);
	}
	else{
		return insert(elem, root->rchild);
	}
	return ;
}

template<typename T, typename Comp>
inline bool BinarySearchTree<T, Comp>::contains(const T& elem, Node* root) const {
	if(NULL == root){
		return false;
	}

	if(elem == root->data){
		return true;
	}
	else if(elem < root->data){
		return contains(elem, root->lchild);
	}
	else{
		return contains(elem, root->rchild);
	}
	return false;
}



#endif /* BSTIMPL_H_ */
