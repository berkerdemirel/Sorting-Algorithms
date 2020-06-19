#include "sorter.h"

// sorting algorithms


// insertion sort
void insertion_sort(vector<int> & arr, int start = 0, int end = -1) {
	int * a = arr.data();
	if (end == -1)
		end = arr.size();
	for (int i = start + 1; i < end; ++i) {
		int num = arr[i];
		int j = i;
		while (j > 0 && num < arr[j - 1]) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = num;
	}
}

// shell sort
bool isSorted(vector<int> & a) {
	int * arr = a.data();
	int n = a.size();
	for (int i = 0; i < n - 1; ++i)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}


void shell_sort(vector<int> & arr, int k) {
	int * a = arr.data();
	int n = arr.size();
	int shell_count = k;
	int* shells = new int[shell_count];
	for (int i = 0; i < shell_count; ++i) {
		shells[i] = 2 * k - 1;
		k--;
	}
	for (int j = 0; j < shell_count; ++j) {
		int & pass = shells[j];
		if (isSorted(arr)) {
			break;
		}
		for (int i = pass; i < arr.size(); i += pass) {
			int num = arr[i];
			int j = i;
			while (j - pass > -1 && num < arr[j - pass]) {
				arr[j] = arr[j - pass];
				j -= pass;
			}
			arr[j] = num;
		}
	}
}

// heap sort
void percDown(int* arr, int i, int n) {
	int child, tmp;
	for (tmp = arr[i]; 2 * i < n; i = child) {
		child = 2 * i;
		if (child != n - 1 && arr[child] < arr[child + 1]) {
			child++;
		}
		if (arr[child] > tmp)
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = tmp;
}


void heap_sort(vector<int> & arr) {
	// add dummy for easy indexing
	arr.push_back(arr[0]);
	arr[0] = INT_MAX;
	int *a = arr.data();
	int n = arr.size();
	// convert arr to maxHeap
	for (int i = arr.size() / 2; i >= 0; --i) {
		percDown(a, i, arr.size());
	}
	for (int i = n - 1; i > 0; --i) {
		swap(a[0], a[i]);
		percDown(a, 0, i);
	}
	arr.resize(arr.size() - 1);
}

// merge sort
void merge(int* arr, int* tmp, int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int nofelements = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (arr[leftPos] <= arr[rightPos])
			tmp[tmpPos++] = arr[leftPos++];
		else
			tmp[tmpPos++] = arr[rightPos++];
	}
	while (leftPos <= leftEnd)
		tmp[tmpPos++] = arr[leftPos++];
	while (rightPos <= rightEnd)
		tmp[tmpPos++] = arr[rightPos++];

	for (int i = 0; i < nofelements; i++, rightEnd--)
		arr[rightEnd] = tmp[rightEnd];
}


void merge_sort(int* arr, int* tmp, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		merge_sort(arr, tmp, left, center);
		merge_sort(arr, tmp, center + 1, right);
		merge(arr, tmp, left, center + 1, right);
	}
}


void merge_sort(vector<int> & arr) {
	int* a = arr.data();
	int n = arr.size();
	int* tmp = new int[n];
	merge_sort(a, tmp, 0, n - 1);
}

// quick sort
int median_of_3(int * a, int left, int right) {
	int center = (left + right) / 2;
	if (a[center] < a[left])
		swap(a[left], a[center]);
	if (a[right] < a[left])
		swap(a[left], a[right]);
	if (a[right] < a[center])
		swap(a[center], a[right]);
	// swap pivot with right
	swap(a[center], a[right - 1]);
	return a[right - 1];
}


int partition(int * arr, int left, int right)
{
	// int pivot = median_of_3(arr, left, right);
	// int pivot = rand() % ((left + right) / 2);
	int pivot = arr[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; ++j)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return (i + 1);
}


void quick_sort_stack(int *arr, int left, int right)
{
	int* stack = new int[right - left];
	int size = 0;
	stack[size++] = left;
	stack[size++] = right;
	while (size) {
		right = stack[--size];
		left = stack[--size];
		while (left < right) {
			int piv = partition(arr, left, right);
			stack[size++] = left;
			stack[size++] = piv - 1;
			left = piv + 1;
		}
	}
}


void quick_sort_recursion(int *arr, int left, int right)
{
	if (left < right) {
		int pi = partition(arr, left, right);
		quick_sort_recursion(arr, left, pi - 1);
		quick_sort_recursion(arr, pi + 1, right);
	}
}


void quick_sort(vector<int> & arr, string type = "recursion") {
	int * a = arr.data();
	int n = arr.size();
	if (type == "recursion")
		quick_sort_recursion(a, 0, n - 1);
	else
		quick_sort_stack(a, 0, n - 1);
}

// radix sort
int getMax(int* arr, int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
		if (max < arr[i])
			max = arr[i];
	return max;
}


void count_sort(int* arr, int n, int exp) {
	int* output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; ++i)
		++count[(arr[i] / exp) % 10];
	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i) {
		int index = (arr[i] / exp) % 10;
		output[count[index] - 1] = arr[i];
		--count[index];
	}
	for (int i = 0; i < n; ++i)
		arr[i] = output[i];
}


void radix_sort(vector<int> & arr) {
	int* a = arr.data();
	int n = arr.size();
	int max = getMax(a, n);
	for (int i = 1; max / i > 0; i *= 10) {
		count_sort(a, n, i);
	}
}

// class functions

sorter::sorter(string fname) {
	ifstream input(fname.c_str());
	if (input.fail()) {
		cout << "there is no such file" << endl;
	}
	else {
		int num;
		while (!input.eof()) {
			input >> num;
			vec.push_back(num);
		}
	}
}

void sorter::sort(string type, int k) {
	double start = omp_get_wtime();
	if (type == "insertion_sort") {
		insertion_sort(vec);
	}
	else if (type == "shell_sort") {
		shell_sort(vec, k);
	}
	else if (type == "heap_sort") {
		heap_sort(vec);
	}
	else if (type == "merge_sort") {
		merge_sort(vec);
	}
	else if (type == "quick_sort_recursion") {
		quick_sort(vec, "recursion");
	}
	else if (type == "quick_sort_stack") {
		quick_sort(vec, "stack");
	}
	else if (type == "radix_sort") {
		radix_sort(vec);
	}
	else if (type == "standard") {
		std::sort(vec.begin(), vec.end());
	}
	else {
		cout << "Sorting algorithm " << type << " is not implemented." << endl;
	}
	double end = omp_get_wtime();
	if (isSorted(vec)) {
		cout << "Sorting finished successfully in " << end - start << " seconds." << endl;
	}
}

void sorter::printVec() {
	for (auto x : vec) {
		cout << x << " ";
	}
	cout << endl;
}

void sorter::setVec(vector<int> & arr) {
	vec = arr;
}

