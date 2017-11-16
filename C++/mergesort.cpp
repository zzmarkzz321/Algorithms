#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

/*
	Merge the compared and sorted indexes in the current iteration of the algorithm. 

	example:

		(After dividing vector container)
		1 	3 	6 	7	3

		1 3		6 7		3

		1 3 6 7		3

		1 3 3 6 7
*/
 
void merge(vector<int>& arr, int p, int m, int r) {
	// Create the max boundries for each array
    int i, j, k;
    int n_l = m - p + 1;
    int n_r =  r - m;
 
    // Create Arrays for both halves
    int L[n_l], R[n_r];
 
    // push the halves into the respective arrays
    for (i = 0; i < n_l; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n_r; j++)
        R[j] = arr[m + 1+ j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0; 
    k = p; 

    while (i < n_l && j < n_r) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy over any remaining elements to the left and right vectors

    while (i < n_l) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n_r) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
	inits the mergeSort algorithm with the divide and conquer (recursive) method. 
	Call mergesort with the lower and upper bounds

	finally, merge until we have atomically separated all indexes
*/
 
void mergeSort(vector<int>& v, int p, int r) {
    if (p < r) {
       
        int m = floor((p+r)/2);

        mergeSort(v, p, m);
        mergeSort(v, m+1, r);
 
        merge(v, p, m, r);
    }
}
 
/*
	Print the vectors container in the following format:

		n;n1;n2;.....nn;
		(enter)
*/

void print(vector<int>& v, int size) {
    int i;
    for (i=0; i < size; i++)
        cout << v[i] << ";";

    cout << endl;
}
 

int main() {
    int size, input;
    vector<int> v;

    cin >> size;

    for (int i = 0; i < size; i++) {
    	cin >> input;
    	v.push_back(input);

    }
 
    mergeSort(v, 0, size - 1);
 
    print(v, size);

    return 0;
}