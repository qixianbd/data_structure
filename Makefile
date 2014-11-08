CXX= g++
CC= g++
CFLAGS=  -c -g -Wall  
CXXFLAGS= -c -g -Wall 
LANG=en_US



.PHONY:all
all: BinarySearchTree_Test.out AvlTree_Test.out Random_Test.out SearchTreePerformanceTest.out Utility_Test.out HashTable_Test.out\
skiplistwithc.out skipList.out SkipList_Test.out


BinarySearchTree_Test.out:BinarySearchTree_Test.o Random.o
	g++ -o $@ $^

BinarySearchTree_Test.o:BinarySearchTree_Test.cc BinarySearchTree.h detail_header/bstImpl.h Random.h

AvlTree_Test.out:AvlTree_Test.o Random.o
	g++ -o $@ $^

AvlTree_Test.o:AvlTree_Test.cc AvlTree.h detail_header/avlImpl.h Random.h

Random_Test.out:Random_Test.o Random.o
	g++ -o $@ $^
	
Random_Test.o:Random_Test.cc Random.h
Random.o:Random.cc Random.h

SearchTreePerformanceTest.out:SearchTreePerformanceTest.o Random.o Utility.o
	g++ -o $@ $^
SearchTreePerformanceTest.o:SearchTreePerformanceTest.cc Random.h AvlTree.h BinarySearchTree.h Utility.h




Utility_Test.out:Utility_Test.o Utility.o Random.o
	g++ -o $@ $^
Utility_Test.o:Utility_Test.cc Utility.h
Utility.o:Utility.cc Utility.h


HashTable_Test.out: HashTable_Test.o Random.o
	g++ -o $@ $^

HashTable_Test.o:HashTable_Test.cc HashTable.h


skiplistwithc.out:skiplistwithc.o
	gcc -o $@ $^
skiplistwithc.o: skiplistwithc.c skiplistwithc.h
	gcc -c -g -o skiplistwithc.o skiplistwithc.c


skipList.out:skipList.o
	g++ -o $@  $^ -lm 
skipList.o:skipList.cc


SkipList_Test.out:SkipList_Test.o Random.o
	g++ -o $@  $^
SkipList_Test.o :SkipList_Test.cc SkipList.h

.PHONY:clean
clean: 
	-rm  -f *.o *.out