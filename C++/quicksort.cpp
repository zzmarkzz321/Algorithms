/*
 * Worst Case Time Complexity: O(nlgn)
 *
 * Author: Mark renzo Santiago
 * University of California, Merced 2016
 * 
 * This implementation of QuickSort was written for the CSE 100: Algorithms Class at UC Merced. 
 */

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/*
 rearrangs the subarray, A[p..r], in place
*/

int partition(vector<int>& A, int p, int r) {
	int pivot, temp;

	pivot = A[r];

	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= pivot) {
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp; 
		}
	}

	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;

}


/*
 just like merge sort, Quicksort uses a divide a conquer method with a worst case Time Complexity of O(nlgn)
*/

void quickSort(vector<int>& A, int p, int r) {

	int q;

	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}

}

/*
	Utlity function to print the resulting, sorted vector 
*/

void printResult(vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ";";
	}

	cout << endl;
}

int main() {

	int size, input, p, r;
	vector<int> A;
	
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> input;
		A.push_back(input);
	}

	p = 0;
	r = size - 1;

	quickSort(A, p, r);
	printResult(A);

	return 0;
}