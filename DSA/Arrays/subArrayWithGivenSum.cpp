#include <iostream>

using namespace std;

void subArrayWithZeroSum(int arr[], int  n) {
    int i, j;
    for(i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) 
                cout << "Subarray [" << i << ".." << j << "]\n";
        }
    }
}

int main(void) {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    subArrayWithZeroSum(arr, n);
    return 0;
}