#include <iostream>
#include<string>

using namespace std;

void getMaxoccuringChar(string str){
	int count[256] = {0};
	int len = str.length();
	int max = 0;
	char result;
	for(int i = 0; i < len; i++){
		count[str[i]]++;
		
		if(count[str[i]] > max){
			max = count[str[i]];
			result = str[i];
		}
	}
/*	int max = 0;
	char result;
	for(int i = 0; i < len; i++){
		if(count[str[i]] > max){
			max = count[str[i]];
			result = str[i];
		}
	}*/
	cout<<result<<" "<<max<<endl;
}

int main() {
	string str = "ramamamamaa";
	getMaxoccuringChar(str);
	return 0;
}