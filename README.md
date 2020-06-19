# Sorting Algorithms in C++
Implementation of popular sorting algorithms in C++

## Insertion Sort
Inserts the ith element in an i-1 length sorted list for i = 1,2,3...n
Complexity : O(N^2)

## Shell Sort
Improves insertion sort with comparing elements that are far from each other. For each pass -where number of passes = K is a hyperparameter- it creates pass distanced sorted arrays, for pass = 2*K-1, 2*K-3 ... 5, 3, 1
Complexity : O(N^(4/3)) 

## Heap Sort
First, creates a max heap from array and performs n swap and n percolate down operations.
Complexity : O(N) + O(N*logN)

## Merge Sort
Merge Sort is a divide and conquer algorithm that first divides the array into equal sized portions. Then conquers by merging sorted portions to build fully sorted array.
Complexity : O(NlogN), + O(N) space complexity

## Quick Sort (with and without recursion)
Quick Sort is a divide and conquer algorithm. It chooses a pivot in each pass and orders the element in the current array in such a way that all the elements in current subarray that are less than pivot gathered in left side of the pivot and all the elements that are greater than the pivot is gathered in the right side.
Complexity : O(NlogN) (average), O(N^2)(worst)
Stack implementation is a little bit faster due to less function call overhead.

## Radix Sort
Radix Sort is not a comparison based sorting algorithm. It sorts the element from the least significant digit to most significant digit iteratively.
Complexity : O(NK) where K is the number of digits of the largest element. (it has O(N) extra space complexity)

Considering both theoretical and practical performance, Radix Sort dominates the others when K is less than logN.
