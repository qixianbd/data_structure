/*
 * BinarySearchTree_Test.cc
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */
#include <iostream>
#include "BinarySearchTree.h"



int main()
{
	BinarySearchTree<int> bt;
	for(int i = 0; i < 10; i++){
		bt.insert(i);
	}
	bt.print();
	int d[] = {5, 3, 4, 2, 1, 7, 6, 9, 8, 10};
	BinarySearchTree<int> btd(d, d+sizeof(d)/sizeof(d[0]));
	btd.print();
	btd.printAsTree();
	bool ret = btd.contains(8);
	std::cout << "ret = " << ret << std::endl;
	//bt.printAsTree();
	//bt.clear();
	//bt.printAsTree();

	for(int i = 1; i < 5; i++){
		btd.remove(i);
	}
	btd.printAsTree();
	return 0;
}



