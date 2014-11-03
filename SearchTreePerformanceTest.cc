/*
 * SearchTreePerformanceTest.cc
 *
 *  Created on: 2014年10月30日
 *      Author: qmwx
 */
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "Random.h"

long long usec(void) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000000)+tv.tv_usec;
}

int main(){

	Random r;
	std::vector<int>  dataset = r.randomUniqueIntArray(0, 64*1024);
	std::vector<int> vInput = r.randomIntArray(0,100*1024, 1024*1024);
	size_t len = vInput.size();


	typedef long long llong;

	{
	std::set<int> s(dataset.begin(), dataset.end());
	llong tstart = usec();
	for(size_t i = 0; i < len; i++){
		s.find(vInput[i]);
	}
	llong tend = usec();
	std::cerr << "map takes time " << double(tend - tstart)/1000 << " ms" << std::endl;
	}



	{
	std::vector<int> vi(dataset.begin(), dataset.end());
	llong tstart = usec();
	sort(vi.begin(), vi.end());
	for(size_t i = 0; i < len; i++){
		binary_search(vi.begin(), vi.end(), vInput[i]);
	}
	llong tend = usec();
	std::cerr << "list takes time " << double(tend - tstart)/1000 << " ms" << std::endl;
	}


	{
	AvlTree<int> avl;
	avl.fillWithArray(dataset);
	llong tstart = usec();
	for(size_t i = 0; i < len; i++){
		avl.contains(vInput[i]);
	}
	llong tend = usec();
	std::cerr << "avl takes time " << double(tend - tstart)/1000 << " ms" << std::endl;
	}

	{
	BinarySearchTree<int> bst;
	bst.fillWithArray(dataset);
	llong tstart = usec();
	for(size_t i = 0; i < len; i++){
		bst.contains(i);
	}
	llong tend = usec();
	std::cerr << "bst takes time " << double(tend - tstart)/1000 << " ms" << std::endl;
	}


	dataset = r.randomUniqueIntArray(0, 10*1024*1024);

	{
		std::set<int> s;
		llong tstart = usec();
		s.insert(dataset.begin(), dataset.end());
		llong tend = usec();
		std::cerr << "set takes time " << double(tend - tstart)/1000 << " ms To Insert. " << std::endl;
	}

	{
		AvlTree<int> avl;
		llong tstart = usec();
		avl.fillWithArray(dataset);
		llong tend = usec();
		std::cerr << "avl takes time " << double(tend - tstart)/1000 << " ms To Insert. " << std::endl;
	}

	{
		BinarySearchTree<int> bst;
		llong tstart = usec();
		bst.fillWithArray(dataset);
		llong tend = usec();
		std::cerr << "bst takes time " << double(tend - tstart)/1000 << " ms To Insert. " << std::endl;
	}

	return 0;
}


