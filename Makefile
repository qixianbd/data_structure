CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: BinarySearchTree_Test.out AvlTree_Test.out Random_Test.out

BinarySearchTree_Test.out:BinarySearchTree_Test.o
	g++ -o $@ $^

BinarySearchTree_Test.o:BinarySearchTree_Test.cc BinarySearchTree.h detail_header/bstImpl.h

AvlTree_Test.out:AvlTree_Test.o Random.o
	g++ -o $@ $^

AvlTree_Test.o:AvlTree_Test.cc AvlTree.h detail_header/avlImpl.h Random.h

Random_Test.out:Random_Test.o Random.o
	g++ -o $@ $^
	
Random_Test.o:Random_Test.cc Random.h
Random.o:Random.cc Random.h

.PHONY:clean
clean: 
	-rm  -f *.o *.out