#include <iostream>
using namespace std;

int main() {
	int Arr[10] = {2, 5, 9, 7, 6, 8};
	int n = 6, k = 3, i, j = k , item = 10;
	cout<<"Before : ";
	for(i = 0; i < n; i++){
		cout<<Arr[i]<<" ";
	}
	while(j < n){
		Arr[j - 1] = Arr[j];
		j = j + 1;
	}
	n = n - 1;
	cout<<"\nAfter : ";
	for(i = 0; i < n; i++){
		cout<<Arr[i]<<" ";
	}
	return 0;
}