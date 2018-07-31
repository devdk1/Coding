#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int a){
    if(a == 1)
        return false;
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
	int n;
	cin>>n;
	cout<<isPrime(n);
	return 0;
}