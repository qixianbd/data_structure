/*
 * SkipList.h
 *
 *  Created on: 2014年11月7日
 *      Author: qmwx
 */

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <iostream>
#include <assert.h>
#include "Random.h"


template<typename T>
class SkipList{
private:
	enum {MAXLEVELCOUNT = 8};
	template<typename U>
	struct SkipNode{
		T data;
		SkipNode *prev;
		SkipNode ** next;
		SkipNode(int levelCount, const U& t):data(t), prev(NULL),next(NULL){
			assert(levelCount >= 0);
			if(levelCount > MAXLEVELCOUNT){
				levelCount = MAXLEVELCOUNT;
			}
			next = new SkipNode* [levelCount+1];
			for(int i = 0; i <= levelCount; i++){
				next[i] = NULL;
			}
		}
		void print(std::ostream &os = std::cout){
			os << data << "\t";
		}
		~SkipNode(){
			delete[] next;
		}
	};
private:
	SkipNode<T> *head;
	int length;
	int levelCount;
public:
	SkipList();
	~SkipList();
	SkipNode<T>* contains(const T& elem);
	void insert(const T& elem);
	void remove(const T& elem);
	void print(std::ostream &os);
};


template<typename T>
SkipList<T>::SkipList():head(NULL), length(0), levelCount(1){
	head = new SkipNode<T>(MAXLEVELCOUNT, T());
}

template<typename T>
SkipList<T>::SkipNode<T>* SkipList<T>::contains(const T& elem) {
	SkipNode<T>* node = head;
	for(int i = levelCount; i >= 0; i--){
		while(node->next[i] &&  node->next[i]->data <= elem){
			node = node->next[i];
			if(node->data == elem){
				return node;
			}
		}
	}
	return NULL;
}

static int randLevelCount(int maxLevelCount){
	double d = 0;
	int level = 0;
	static Random r;
	while(1){
		d = r.nextDouble(0.0, 1.0);
		std::cerr << "d = " << d << std::endl;
		if(d < 0.5){
			level++;
			if(level >= maxLevelCount){
				return maxLevelCount;
			}
		}
		else{
			return level;
		}
	}
}



template<typename T>
void SkipList<T>::insert(const T& elem) {
	SkipNode<T>* node = head;
	SkipNode<T>* needUpdate[MAXLEVELCOUNT+1] = {0};
	for(int i = levelCount; i >= 0; i--){
		while(node->next[i] &&  node->next[i]->data <= elem){
			node = node->next[i];
		}
		needUpdate[i] = node;
	}
	int level = randLevelCount(MAXLEVELCOUNT);
	SkipNode<T>* x = new SkipNode<T>(level, elem);

	if(level <= levelCount){
		for(int i = 0; i <= level; i++){
			x->next[i] = needUpdate[i]->next[i];
			needUpdate[i]->next[i] = x;
		}
	}
	else{
		for(int i = 0; i <= levelCount; i++){
			x->next[i] = needUpdate[i]->next[i];
			needUpdate[i]->next[i] = x;
		}

		for(int i = levelCount+1; i <= level; i++){
			head->next[i] = x;
			x->next[i] = NULL;
		}
	}

	if(level > levelCount){
		levelCount = level;
	}
	length++;
}

template<typename T>
void SkipList<T>::remove(const T& elem) {
}

template<typename T>
inline SkipList<T>::~SkipList() {
	SkipNode<T> *node = head->next[0];
	while(node){
		head->next[0] = node->next[0];
		SkipNode<T> *p = node->next[0];
		delete node;
		node = p;
	}
	delete head;
}

template<typename T>
void SkipList<T>::print(std::ostream& os) {
	SkipNode<T> *node = head;
	for(int i = levelCount; i >= 0; i--){
		node = head->next[i];
		os << "The " << i << " level: ";
		while(node){
			node->print(os);
			node = node->next[i];
		}
		os << "\n";
	}
}

#endif /* SKIPLIST_H_ */
