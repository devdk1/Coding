#include <iostream>
using namespace std;

int main() {
	int Arr[10] = {1, 5, 9, 7, 6, 8};
	int k = 3, n = 6,item = 10;
	int i, j = n - 1;
	cout<<"Before :";
	for(i = 0; i < n; i++){
		cout<<Arr[i]<<" ";
	}
	cout<<"\n";
	n = n + 1;
	while(j >= k){
		Arr[j + 1] = Arr[j];
		j = j - 1;
	}
	Arr[k] = item;
	cout<<"\nAfter :";
	for(i = 0; i < n; i++){
		cout<<Arr[i]<<" ";
	}
	return 0;
}