#include <iostream>
#include <string>
using namespace std;

bool checkSubString(string firstString, string secondString){
	int sizeOfFirst = firstString.size();
	int sizeOfSecond = secondString.size();
	if(sizeOfSecond > sizeOfFirst)
		return false;
	
	for(int i = 0; i < sizeOfFirst; i++){
		int j = 0;
		if(firstString[i] == secondString[j]){
			while(firstString[i] == secondString[j] && j < sizeOfSecond){
				j++;
				i++;
			}
			if(j == sizeOfSecond)
				return true;
		}
	}
	return false;
}

int main() {
	string firstString, secondString;
	cin>>firstString>>secondString;
	if(checkSubString(firstString,secondString))
		cout << "Second string is a substring of the frist string."<<endl;
	else
		cout << "Second string is not a substring of the first string."<<endl;
	
	return 0;
}