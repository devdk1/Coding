#include <iostream>
using namespace std;

int pow(int a, int b){
	int val = 1;
	for(int i = 0; i < b; i++){
		val = val * a;
	}
	return val;
}

int main() {
	int a, b;
	cin>>a>>b;
	cout<<pow(a, b);
	return 0;
}