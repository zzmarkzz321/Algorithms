#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*

	Author @MarkRenzoSantiago

	Insertion sort implementation

	Created for UCM CSE 100 Algorithms class

	1 5 4 8 7

	1 5

	1 4 5

	1 4 5 8

	1 4 5 7 8

	current = 5
	previous = 1

	if current < previous and previous_index >= 0
		then switch current and previous indexes

	print current hand 

*/

/*
1 5 2 4 3 
1 5
1 5 2 -> 1 2 5

*/

void printCurrent(vector<int>& A, int hand_size) {
	for (int i = 0; i < hand_size+1; i++) {
		cout << A[i] << ";";
	}
	cout << endl;
}

void insertionSort(vector<int>& A, int n) {

	int curr_i, prev_i, key, i, hand_size = 1;

	for (curr_i = 1; curr_i < A.size(); curr_i++) {
		prev_i = curr_i - 1;
		i = curr_i;
		while (prev_i >=0 && A[i] < A[prev_i]) {
			key = A[i];
			A[i] = A[prev_i];
			A[prev_i] = key;

			prev_i = prev_i - 1;
			i = i - 1;
		}

		printCurrent(A, hand_size);
		hand_size = hand_size + 1;
	}
}


int main() {

	int n, input;
	cin >> n;
	vector<int> arr;

	for (int i=0; i<n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	insertionSort(arr, n);

return 0;
}
