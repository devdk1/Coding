#include <iostream>

using namespace std;

int countOnes(int arr[], int l, int r) {
    if(l <= r) {
        int mid = l + (r - l) / 2;

        if(mid == r || (arr[mid] == 1 && arr[mid + 1] == 0))
            return mid + 1;
        if(arr[mid] == 1)
            return countOnes(arr, mid + 1, r);
        return countOnes(arr, l, mid - 1);
    }
    return 0;
}

int main(void) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        int i = 0;
        while(i < n)
            cin>>arr[i++];

        cout<<countOnes(arr, 0, n - 1)<<endl;
        return 0;   
    }
}