#include <iostream>
#include <string>
using namespace std;

int main() {
	string T = "test string";
	string P = "mask";
	int n = T.length();
	int m = P.length();
	int k = 0, j;
	char hash[n];
	for(int i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(T[i] == P[j]){
				break;
			}
		}
		if(j == m){
			hash[k++] = T[i];
		}
	}
	hash[k] = '\0';
	for(int i = 0; hash[i] != '\0'; i++){
		cout<<hash[i]<<" ";
	}

	return 0;
}
