/*
 *
 * Author: Mark renzo Santiago
 * University of California, Merced 2017
 * 
 * This implementation of Matrix Chain Multiplication was written for the CSE 100: Algorithms Class at UC Merced. 
 * 
 * Description:
 *  dynamic programming algorithm: matrix chain multiplication (chapter 15.2), where the goal is to ﬁnd the most 
 *  computationally eﬃcient matrix order when multiplying an arbitrary number of matrices in a row
 * 
 * Credit:
 * Sudo code source: GeeksforGeeks.com and Text book
 */


#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print(int **s, int i, int j) {

    if(i == j)
        cout<<"A"<<i-1;
    
    else {
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1, j);
        cout<<")";
    }       
}

void matrix_multiplication(int p[], int n) {

    int m[n+1][n+1]; 
    int i, j, k, L, q;
    int ** s;
    
    s =  new int* [n+1];
    
    for(i = 1; i < (n+1); i++)
        s[i] =  new int [n+1];
    
    for (i = 1; i < n+1; i++)
        m[i][i] = 0;
 
    for (L = 2; L < n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
    
            for (k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
   
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    cout << m[1][n-1] << endl;
    
    print(s, 1, n-1);     
    
    cout << endl;      
}

int main() {

    int n;  
    cin >> n;
    
    int p[n+1];
    
    for(int i = 0; i < n + 1 ; i++) {
        cin >> p[i];
    }
    
    int size = sizeof(p)/sizeof(p[0]);
       
    matrix_multiplication(p, size);
     
}