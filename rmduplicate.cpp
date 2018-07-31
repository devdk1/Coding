#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin>>str;
	int len = str.length();
	int tail = 1;
	for(int i = 1; i < len; i++){
		int j;
		for(j = 0; j < tail; j++){
			if(str[i] == str[j])
				break;
		}
		if(j == tail){
			str[tail] = str[i];
			tail++;
		}
	}
	str[tail] = '\0';
	for(int i = 0; str[i] != '\0'; i++)
		cout<<str[i];
	return 0;
}