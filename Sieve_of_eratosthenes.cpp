#include <iostream>
#include <vector>
using namespace std;

void Sieve(int n){
    vector<int> val(n+1,1);
	val[0] = 0;
	val[1] = 0;
    for(int i = 2; i <= n; i++){
		if(val[i] == 1){
        for(int j = 2; i * j <= n; j++)
			val[i * j] = 0;
		cout<<i<<" ";		
	}
 }
}

int main() {
    int n;
    cin>>n;
    Sieve(n);
	return 0;
}