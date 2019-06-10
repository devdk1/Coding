#include <iostream>

using namespace std;

int maxSum(int arr[], int n) {
    /**
     * TODO
     */ 
}

int main(void) {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int max_sum = maxSum(arr, n);
    cout<<max_sum<<endl;
}