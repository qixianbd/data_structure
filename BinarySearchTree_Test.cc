/*
 * BinarySearchTree_Test.cc
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Random.h"


int main()
{
#if !1
	BinarySearchTree<int> bt;
	for(int i = 0; i < 10; i++){
		bt.insert(i);
	}
	bt.print();
#endif

#if !2
	int d[] = {5, 3, 4, 2, 1, 7, 6, 9, 8, 10};
	BinarySearchTree<int> btd(d, d+sizeof(d)/sizeof(d[0]));
	btd.print();
	btd.printAsTree();

	BinarySearchTree<int> btd2(btd);
	btd2.printAsTree();
	std::cout << "The max is :" << btd2.findMax() << std::endl;
	std::cout << "The hight is: " << btd2.hight() << std::endl;
	btd2.printToDot();

	Random r;
	std::vector<int> v =  r.randomUniqueIntArray(1, 256);
	BinarySearchTree<int> bst;
	bst.fillWithArray(v);
	std::ofstream fout("bst_tree.dot");
	bst.printToDot(fout);
#endif

#if !3
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

	BinarySearchTree<int> bst;
	Random r;
	bst.fillWithArray(r.randomUniqueIntArray(0, 25));
	bst.print(std::cerr);
	std::ofstream fout("bst_tree_small.dot");
	bst.printToDot(fout);
	for(int i = 0; i < 30; i++){
		bool ret = bst.contains(i);
		std::cerr << ret << std::endl;
	}

	return 0;
}



