#include <iostream>

using namespace std;
void zigZag(int a[], int n) {
    bool flag = true;
    for(int i = 0; i < n - 1; i++) {
        if(flag && a[i] > a[i+1])
            swap(a[i], a[i+1]);
        else if(!flag && a[i] < a[i+1])
            swap(a[i], a[i+1]);
        flag = !flag;
    }
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i < n; i++)
        cin>>arr[i];
    zigZag(arr, n);
    return 0;
}