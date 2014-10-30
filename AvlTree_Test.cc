/*
 * AvlTree_Test.cc
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Random.h"
#include "AvlTree.h"


int main(){
	AvlTree<int> bt;
	for(int i = 0; i < 10; i++){
		bt.insert(i);
	}
	bt.print(std::cerr);
	bt.printAsTree(std::cerr);
	std::cerr << "height = " << bt.hight() << std::endl;
	bt.printToDot(std::cerr);


	AvlTree<int> avl;
	Random r;
	std::cerr << "***********************" << std::endl;
	std::vector<int> vi = r.randomUniqueIntArray(0, 256);
	std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cerr, " "));
	avl.fillWithArray(vi);
	avl.printAsTree(std::cerr);

	std::ofstream fout("avltree.dot");
	avl.printToDot(std::cerr);
	avl.printToDot(fout);

	return 0;

}


