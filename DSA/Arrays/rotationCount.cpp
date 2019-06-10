#include <iostream>

using namespace std;

/**
 * worst case O(n)
 */ 
int rotationCount(int arr[], int n) {
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i]) {
            res = i;
            break;
        }
    }
    return res;
}

/**
 * Using Binary search O(Log n)
 */
int countRotations(int arr[], int low, int high) {
    if(high < low)
        return 0;
    if(high == low)
        return low;
} 

int main(void) {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int rotations = rotationCount(arr, n);
    cout<<rotations<<endl;
}