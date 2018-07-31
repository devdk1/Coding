#include <iostream>
using namespace std;

void replaceSpace(char s[], int len){
	int i = 0, count = 0;
	for(i = 0; i < len; i++){
		if(s[i] == ' ')
			count++;
	}
	cout<<count<<endl;
	
	int newLength = len + count * 2;
	s[newLength] = '\0';
	for(i = len - 1; i >= 0; i--){
		if(s[i] == ' '){
			s[newLength - 1] = '0';
			s[newLength - 2] = '2';
			s[newLength - 3] = '%';
			newLength = newLength - 3;
		}
		else{
			s[newLength - 1] = s[i];
			newLength = newLength - 1;
		}
	}
}

int main() {
	char s[] = "my name is khan";
	int len = 15;
	replaceSpace(s,len);
	for(int i = 0; s[i] != '\0'; i++)
		cout<<s[i];
	return 0;
}