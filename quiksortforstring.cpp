#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(char str[], int l, int r){
		char pivot = str[r];
		int pIndex = l, i;
		for( i = l; i < r ; i++){
			if(str[i] <= pivot){
				swap(&str[i], &str[pIndex]);
				pIndex++;
			}
		}
		swap(&str[pIndex], &str[i]);
		return pIndex;
}
void QuickSort(char str[], int l, int r){
	if(l < r){
		int pIndex = Partition(str, l, r);
		QuickSort(str, l, (pIndex - 1));
		QuickSort(str, (pIndex + 1), r);
	}
}

int main() {
	char str[] = "sample";
	int len = 0;
	while(str[len] != '\0')
        len++;
	QuickSort(str, 0, len - 1);
	for(int i = 0; i < len; i++){
		cout<<str[i]<<" ";
	}
	return 0;
}
