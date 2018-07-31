#include <iostream>
using namespace std;

int main() {
	int Arr[] = {1,2,3,4,5,3,2,1};
	for(int i = 0; i < 8; i++){
		for(int j = i + 1; j < 8; j++){
			if(Arr[i] == Arr[j])
				cout<<Arr[i]<<" ";
		}
	}
	return 0;
}