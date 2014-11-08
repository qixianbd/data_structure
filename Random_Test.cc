/*
 * Random_Test.cc
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */
#include <iostream>
#include <iterator>
#include "Random.h"

int main()
{

	Random r;
#if 1
	for(int j = 0; j < 30; j++){
		int i = r.nextInt(10, 20);
		std::cerr << "i = " << i << std::endl;
	}
	std::vector<int> v = r.randomUniqueIntArray(45, 65);
	for(unsigned int i = 0; i < v.size(); i++){
		std::cerr << v[i] << "\t";
	}
	v = r.randomIntArray(0, 10, 25);
	std::cerr << std::endl;
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cerr, " "));
	std::cerr << "\n****************************" << std::endl;

	double min = 1000.00, max = -1.0;
	for(int j = 0; j < 10; j++){
		double d  = r.nextDouble(0.0, 1.0);
		max = max >= d ? max : d;
		min = min <= d ? min : d;

		std::cerr << d << "  ";
	}
	std::cerr << "\nmax = " << max << ", min = " << min << std::endl;

	std::vector<double> dv = r.randomDoubleArray(73.2, 98.9, 100);
	std::copy(dv.begin(), dv.end(), std::ostream_iterator<double>(std::cerr, "\n"));
#endif

#if !2
	std::vector<std::string> stringVector;
	for(int i = 0; i < 64; i++){
		stringVector.push_back(r.getFixLengthString(6));
	}
	//std::copy(stringList.begin(), stringList.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::sort(stringVector.begin(), stringVector.end());
	std::copy(stringVector.begin(), stringVector.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));
#endif

#if !2
	std::vector<std::string> stringVector;
	for(int i = 0; i < 16; i++){
		stringVector.push_back(r.getPhoneNum(11));
	}
	//std::copy(stringList.begin(), stringList.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::sort(stringVector.begin(), stringVector.end());
	std::copy(stringVector.begin(), stringVector.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));

	std::cerr <<"**************************" << std::endl;
	stringVector.clear();
	const char* digitArray[] = {"138", "139", "159", "168"};
	for(int i = 0; i < 16; i++){
		stringVector.push_back(r.getPhoneNumWithPrefix("159", 11));
	}
	//std::copy(stringList.begin(), stringList.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::sort(stringVector.begin(), stringVector.end());
	std::copy(stringVector.begin(), stringVector.end(), std::ostream_iterator<std::string>(std::cerr, "\n"));
#endif

	return 0;

}



