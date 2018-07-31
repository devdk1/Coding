#include <iostream>
using namespace std;

void getMaxoccuringChar(char *str){
	int count[256] = {0};
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		count[str[i]]++;
	}
	int max = 0;
	char result;
	for(int i = 0; i < len; i++){
		if(count[str[i]] > max){
			max = count[str[i]];
			result = str[i];
		}
	}
	cout<<result<<" "<<max<<endl;
}

int main() {
	char str[] = "sample string";
	getMaxOccurringChar(str);
	return 0;
}