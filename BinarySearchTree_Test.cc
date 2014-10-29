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
#if 0
	BinarySearchTree<int> bt;
	for(int i = 0; i < 10; i++){
		bt.insert(i);
	}
	bt.print();
#endif
	int d[] = {5, 3, 4, 2, 1, 7, 6, 9, 8, 10};
	BinarySearchTree<int> btd(d, d+sizeof(d)/sizeof(d[0]));
	btd.print();
	btd.printAsTree();

	BinarySearchTree<int> btd2(btd);
	btd2.printAsTree();
	std::cout << "The max is :" << btd2.findMax() << std::endl;
	std::cout << "The hight is: " << btd2.hight() << std::endl;
#if 0
	bool ret = btd.contains(8);
	std::cout << "ret = " << ret << std::endl;
	//bt.printAsTree();
	//bt.clear();
	//bt.printAsTree();

	for(int i = 1; i < 5; i++){
		btd.remove(i);
	}
	btd.printAsTree();
#endif
	return 0;
}



