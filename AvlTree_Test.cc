/*
 * AvlTree_Test.cc
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */

#include <iostream>
#include "AvlTree.h"


int main(){
	AvlTree<int> bt;
	for(int i = 0; i < 10; i++){
		bt.insert(i);
	}
	bt.print();
	bt.printAsTree();
	std::cerr << "height = " << bt.hight() << std::endl;
}


