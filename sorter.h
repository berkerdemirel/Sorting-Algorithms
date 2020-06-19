#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <string>

using namespace std;

class sorter {
public:
	sorter(vector<int> & arr) : vec(arr) {};
	sorter(string fname);
	void sort(string type = "heap_sort", int k = 1);
	void printVec();
	void setVec(vector<int> & arr);
private:
	vector<int> vec;
};

#endif