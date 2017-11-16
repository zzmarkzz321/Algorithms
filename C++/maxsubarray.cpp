#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/* 

Given an array of size n

Find the subarray with the biggest summation for the given array

Ex:
	arr = [-5. -3, 5, 7, 2, 14, 3, 11, -3]

	since the sub array [5, 7, 2, 14, 3, 11] returns teh greatest sum in the array arr, we will return: 42 (sum of that sub array)

Explanation of Ex:
	we recursively break down the array until we've reach the atomical size (1)

	from each iteration, we compare the sum of those values and return the greatest
	
*/

/*
Pseduo Code:
	
	1) Divide array into two halves

	2) break down until we've reached the most atomicaly sized array (n = 1)

	3) compare the left and right most sub array and find the max of the sub array.
*/

// Finds the maximum of the current array
int findMax(int left, int right, int crossing) {

	// compare all three and find the sum of them
	int max = ((left > right) ? left : right);
	return ((max > crossing) ? max : crossing);

}

// 1 <= low <= mid <= high <= n
// aside from checking the left and right most from the mid point, we have to check the bounds from the min to the max
// for the sums of either side, return the largest sum
int crossingMidpoint(vector<int>& v, int low, int mid, int high) {
	int sum = 0;
	// find the sum of the right
	int rightSum = 0;
	for (int r_i = mid; r_i >= low; r_i--) {
		sum += v[r_i];
		if (sum > rightSum)
			rightSum = sum;
	}

	// find the sum of the left
	sum = 0;
	int leftSum = 0;
	for (int l_i = mid+1; l_i <= high; l_i++) {
		sum += v[l_i];
		if (sum > leftSum)
			leftSum = sum;
	}

	return leftSum + rightSum;
}

// Just like the merge sort algorithm, this function will recursively break down the array into sub arrays.
// It will return the maxium sum 
int maxSubArray(vector<int>& v, int low, int high) {

	if (low == high)
		return v[low];

	// init midpoint
	int midpoint = floor(low + high)/2;

	// recursiely divide arrays into sub arrays
	return findMax(
			maxSubArray(v, low, midpoint),
			maxSubArray(v, midpoint+1, high),
			crossingMidpoint(v, low, midpoint, high)
		);

}

int main() {

	int n, input;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	cout << maxSubArray(v, 0, n) << endl;

	return 0;
}