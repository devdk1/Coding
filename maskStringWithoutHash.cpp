#include <iostream>
#include <string>
using namespace std;

int main() {
	string T = "test string";
	string P = "mask";
	int n = T.length();
	int count[256] = {0};
	int k = 0;
	//char hash[n];
	for(int i = 0; i < 256; i++){
		count[P[i]]++;
	}	
	for(int i = 0; i < n; i++){
		if(count[T[i]] == 0){
			T[k++] = T[i];
		}
	}	
	T[k] = '\0';
	for(int i = 0; T[i] != '\0'; i++){
		cout<<T[i]<<" ";
	}
	return 0;
}
