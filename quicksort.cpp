#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int Arr[], int start, int end){
	int pivot = Arr[end];
	int pIndex = start;
	for(int i = start; i < end; i++){
		if(Arr[i] <= pivot){
			swap(&Arr[i],&Arr[pIndex]);
			pIndex++;
		}
	}
    swap(&Arr[pIndex],&Arr[end]);
	return pIndex;
}

void quickSort(int Arr[], int start, int end){
	if(start < end){
		int pIndex = partition(Arr[],start,end);
		quickSort(Arr[],start,pIndex - 1);
		quickSort(Arr[],pIndex+1,end);				
}

int main() {
	int Arr[] = {5, 8 , 1 , 6 , 7 , 4 , 9 , 10, 91, 19, 86, 35};
	quickSort(Arr, 0, 11);
	for(int i = 0; i < 12; i++){
		cout<<Arr[i]<<" "<<;
	}  
	return 0;
}