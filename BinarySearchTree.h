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
#include <vector>
#include <map>

template <typename T, typename Comp = std::less<T> >
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& bst);
	BinarySearchTree(const T* beg, const T* end);
	~BinarySearchTree();
	const BinarySearchTree& operator=(const BinarySearchTree& bst);


	void fillWithArray(const std::vector<T>& v){
		for(size_t i = 0; i < v.size(); i++){
			insert(v[i]);
		}
	}
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

	Node* proot;
	Comp cmp;
	size_t len;
	bool contains(Node* root, const T& elem)const;
	void insert(Node* &root, const T& elem);
	void remove(Node* &root, const T& elem);
	void print(Node* root, std::ostream& os);
	void printAsTree(Node* root, std::ostream& os);
	void printToDot(const Node* root, std::ostream& os){
		//std::queue<AvlNode<T>* > que;
		if(NULL == root){
			return ;
		}
		os << "\ndigraph G{\n";
		os << "\tlabel = " << "\"binary_search_tree\"";
		os << "\tstyle = \"dashed\";\n";
		os << "\tcolor = purple;\n";

		//typedef typename BinarySearchTree<T, Comp>::Node TNode;
		std::vector<const Node* > nodeList;
		size_t ip = 0, ichild = 0;
		nodeList.push_back(root);
		const Node* pNode = root;
		while(ip < nodeList.size()){
			pNode = nodeList[ip];
			os << "\tNode" << ip << " [ label = \"" << pNode->data << " \"];\n";
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
	size_t hight(Node* root)const{
		if(NULL == root){
			return 0;
		}
		return std::max(hight(root->lchild), hight(root->rchild))+1;
	}
	Node* clone(const Node* root){
		if(NULL == root){
			return NULL;
		}
		Node *p = new Node(root->data, NULL, NULL);
		insert(proot, root->data);
		clone(root->lchild);
		clone(root->rchild);
		return proot;
	}

	size_t size(Node* root)const;
	void clear(Node* &root);

	Node* findMin(Node* root)const{
		if(root == NULL){
			return NULL;
		}
		if(root->lchild == NULL){
			return root;
		}
		else{
			Node* pos = root;
			while(pos->lchild != NULL){
				pos = pos->lchild;
			}
			return pos;
		}
	}
	Node* findMax(Node* root)const{
		if(root == NULL){
			return NULL;
		}
		if(root->rchild == NULL){
			return root;
		}
		else{
			return findMax(root->rchild);
		}
	}
};



#include "detail_header/bstImpl.h"

#endif /* BINARYSEARCHTREE_H_ */
