#include "sorter.h"

using namespace std;

#define N 1e3
#define K 2e9

int main() {
	vector<int> arr((int)N);
	generate(arr.begin(), arr.end(), []() {return rand() % (int)K; });
	sorter s(arr);
	double start = omp_get_wtime();
	s.sort("standard");

	return 0;
}