#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int len, max = 0, sec_max = 0;
        cin>>len;
        int arr[len];
        for(int i = 0; i < len; i++) {
            cin>>arr[i];
        }
        for(int i = 0; i < len; i++) {
            if(arr[i] > max) {
                sec_max = max;
                max = arr[i]; 
            }
            else if(arr[i] > sec_max && arr[i] != max) 
                sec_max = arr[i];
        }
        cout<<"Second maximum is : "<<sec_max<<endl;
    }
}