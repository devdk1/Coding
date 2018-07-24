#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int len, i;
        cin>>len;
        int arr[len];
        for(int i = 0; i < len; i++) {
            cin>>arr[i];
        }
        int state = 1;
        for(i = 1; i < len; i++) {
            if(state == 1){
                if(arr[i - 1] == arr[i]){
                    state = 2;
                }
                else if(arr[i - 1]  > arr[i]){
                    state = 3;
                }
            }
            else if(state == 2) {
                if(arr[i - 1] > arr[i]){
                    state = 3;
                }
                else if(arr[i - 1] < arr[i ]) {
                    break;
                }
            }
            else {
                if(arr[i - 1] <= arr[i]){
                    break;
                }   
            }
        }
        if(i != len)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
	return 0;
}
