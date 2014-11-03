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
	}


	return 0;
}

