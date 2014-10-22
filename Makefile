CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: BinarySearchTree_Test.out

BinarySearchTree_Test.out:BinarySearchTree_Test.o
	g++ -o $@ $^

BinarySearchTree_Test.o:BinarySearchTree_Test.cc BinarySearchTree.h

.PHONY:clean
clean: 
	-rm  -f *.o *.out