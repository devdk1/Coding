#include <iostream>
#include <vector>
using namespace std;

void twoMissingNumber(int arr[], int n) {
    vector<bool> mark(n+1, false);
    for(int i = 0; i < n - 2; i++)
        mark[arr[i]] = true;
    for(int i = 1; i <= n - 2; i++) {
        if(!mark[i])
        cout<<i<<" ";        
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        int arr[len];
        for(int i = 0; i < len; i++) {
            cin>>arr[i];
        }
        twoMissingNumber(arr, len + 2);
    }
    return 0;
}