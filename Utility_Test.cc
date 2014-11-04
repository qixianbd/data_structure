/*
 * Utility_Test.cc
 *
 *  Created on: 2014年11月3日
 *      Author: qmwx
 */
#include <iostream>
#include <algorithm>
#include <iterator>

#include "Random.h"
#include "Utility.h"
#include "assert.h"


void testEndWithSubString(){
	std::cerr << "TEST ENDWITHSUBSTRING$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	Random r;
	for(int i = 0; i < 32; i++){
		std::string str = r.getPhoneNum(8);
		std::string sub = r.getRandomString(3);
		str += sub;
		std::cerr << str << "\t" << sub << "\t";
		std::cerr << endWithSubString(str, sub) << std::endl;
	}
	const char* endChar[] = {"a", "e", "i", "o", "u"};
	for(int i = 0; i < 32; i++){
		std::string str = r.getRandomString(6);
		std::string sub = endChar[i%5];
		std::cerr << str << "\t" << sub << "\t";
		std::cerr << endWithSubString(str, sub) << std::endl;
	}
}



int main()
{
#if !1
	typedef long long int llong;
	llong start = usec();
//	sleep(1);
	llong end = usec();
	std::cerr << end - start << std::endl;

	long number[] = {0, 127, -3, 255, 1024*1024*1024*2-1, -4, 4, 5, 6, 1, -1,  128};
	int len = sizeof(number)/sizeof(number[0]);

	for(int i = 0; i < len; i++){
		std::cerr << longToBinaryString(number[i]) << std::endl;
	}
#endif

	long number[] = {0, 127, -3, 255, 1024*1024*1024*2-1, -4, 4, 5, 6, 1, -1,  128};
	int len = sizeof(number)/sizeof(number[0]);

	for(int i = 0; i < len; i++){
		std::cerr << longToString(number[i]) << std::endl;
	}

	char *p = new char[10];
	char *q = new char[10];
	strncpy(p, "abcdefghi", 10);
	strncpy(q, "123456789", 10);
	memSwap(p, q, 10);
	std::cerr << p << "\t" << q << '\n';
	delete[] p;
	delete[] q;

	long number2[] = {128, 1, -4, 255, 1024*1024*1024*2-1, -4, 4, 5, 6, 1, -1,  -128};
	memSwap(number,number2, sizeof(number) );
	std::copy(number, number + len, std::ostream_iterator<long>(std::cerr, "\t"));
	std::cerr << std::endl;

	std::copy(number2, number2 + len, std::ostream_iterator<long>(std::cerr, "\t"));
	std::cerr << std::endl;


	std::cerr << "********************" << std::endl;
	Random r;
	for(int i = 0; i < 32; i++){
		std::string str = r.getRandomString();
		const char* buf = str.c_str();

		char* bufCpy = new char[str.length() + 1];
		strncpy(bufCpy, buf, str.length());
		int lenOfString = strlen(buf);
		for(int j = 0; j < lenOfString; j++){
			int k = r.nextInt(0, 2);
			if(k){
				bufCpy[j] = toupper(bufCpy[j]);
			}
		}
		bufCpy[str.length()] = '\0';

		std::cerr << str << '\t' << bufCpy << '\t' ;
		std::cerr << stringCmpIngoreCase(buf, bufCpy) << std::endl;
		delete[] bufCpy;
	}

	static const char* digitArray[] = {"131", "139", "159", "151", "183"};
	int arrayLength = sizeof(digitArray)/sizeof(digitArray[0]);

	for(int i = 0; i < 52; i++){
		int index = r.nextInt(0,arrayLength);
		const char* prefix = digitArray[index];
		std::string theString = r.getPhoneNumWithPrefix(NULL, 11);
		std::cerr << prefix << "\t" << theString;
		std::cerr << "\t" << startWithSubString(theString, std::string(prefix)) << std::endl;

	}

	assert(isAllDigit(std::string("123")));
	assert(isAllDigit(std::string("")));
	assert(!isAllDigit(std::string("a1231 da")));
	assert(isAllDigit(std::string("1")));
	assert(!isAllDigit(std::string("1423523564 374376473473")));
	assert(!isAllDigit(std::string("A")));


	testEndWithSubString();
	std::cerr << "All Test Pasted." << std::endl;

	return 0;
}

