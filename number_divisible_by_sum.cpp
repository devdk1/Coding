#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin>>T;
    while(T--) {
        cin>>N;
		int temp = N;
        int sum = 0;
        while(N) {
            sum += N % 10;
            N = N /10;
        }
        
        (temp % sum == 0) ? cout<<"1"<<endl : cout<<"0"<<endl;
    }
	return 0;
}