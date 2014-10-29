/*
 * Random.h
 *
 *  Created on: 2014年10月29日
 *      Author: qmwx
 */

#ifndef RANDOM_H_
#define RANDOM_H_
#include<vector>
class Random{
public:
	Random(unsigned long s = 1);
	int nextInt(unsigned int beg, unsigned int end);
	int nextInt(int n);
	double nextDouble();
	double nextDouble(double beg, double end);
	std::vector<int> randomUniqueIntArray(int beg, int end);
	std::vector<int> randomIntArray(int beg, int end, int n);
	std::vector<double> randomDoubleArray(double beg, double end, int n);
private:
	unsigned long seeds;
};



#endif /* RANDOM_H_ */
