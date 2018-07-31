#include <iostream>
using namespace std;

int main() {
	int Arr[] = {5,7,9,-10,19,445,79};
	int iMin = Arr[0];
	int iMax = Arr[0];
	for(int i = 1; i < 7; i++){
		if(Arr[i] < iMin)
			iMin = Arr[i];
		if(Arr[i] > iMax)
			iMax = Arr[i];
	}
	cout<<iMin<<" "<<iMax;
	return 0;
}