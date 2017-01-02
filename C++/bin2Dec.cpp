

#include <vector>
#include <iostream>


using namespace std;

// Converts decimal to binary

vector<int> bconvertd(int n) {
    
    vector<int> binaryDigits;
    
    while (n > 0) {
        int digit = n%2;
        n = n/2;
        
        binaryDigits.push_back(digit);
    }

    return binaryDigits;
}

// find the max consecutive number of 1's in the binary sequence
void maxOnes(vector<int> binaryForm) {
    int max = 0;
    int tempMax = 0;
    for (int i = 0; i < binaryForm.size(); i++) {
        if (binaryForm[i] == 1){
            tempMax++;
            if (tempMax > max) {
                max = tempMax;
            }
        } 

        else {
            tempMax = 0;
        }
    }

    cout << max << endl;
}

int main(){
    
    int n;
    cin >> n;
    
    maxOnes(bconvertd(n));
    
    return 0;
}
