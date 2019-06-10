#include <iostream>

using namespace std;

/**
 * This function returns true if arr[0..n-1] has a pair with sum equals to x.
 */ 
bool pairWithGivenSum(int arr[], int n, int sum) {
    /**
     * Find the pivot element (maximum element)
     */ 
    int i;
    for(i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1])
            break;
    }

    int l = (i + 1) % n;
    int r = i;

    while(l != r) {
        if(arr[l] + arr[r] == sum)
            return true;
        if(arr[l] + arr[r] > sum)
            r = (n + r - 1) % n;
        else
            l = (l + 1) % n;
    }
    return false;
}
 
int main(void) {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int sum;
    cin>>sum;
    if(pairWithGivenSum(arr, n, sum))
        cout<<"Array has elements with given sum"<<endl;
    else
        cout<<"Array don't have elements with given sum"<<endl;
    
    return 0;
}