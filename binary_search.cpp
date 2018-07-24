#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int l, int r) {
   while(r >= l) {
        int mid = l + ( r - l ) / 2;
        if(arr[mid] == n)
            return mid;
        if(arr[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
   } 
   return -1;
}
int main() {
    int len, num;
    cin>>len;
    int arr[len];
    for(int i = 0; i < len; i++)
        cin>>arr[i];
    cin>>num;
    int result = binarySearch(arr, num, 0, len - 1);
    if(result == -1)
        cout<<"Not Found"<<endl;
    else
        cout<<result<<endl;

    return 0;
}