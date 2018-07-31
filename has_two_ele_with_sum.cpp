#include <iostream>
using namespace std;

void QuickSort(int Arr[], int start, int end);

bool hasTwoElements(int Arr[] ,int size,int sum){
	int l, r;
	
	QuickSort(Arr,l, size - 1);
	l = 0;
	r = size - 1;
	
	while(l < r){
		if(Arr[l] + Arr[r] == sum){
			return 1;
		}else if(Arr[l] + Arr[r] < sum) l++;
		else r--;
	}
	return 0;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int Arr[], int start, int end){
	int pivot = Arr[end];
	int pIndex = start;
	for(int i = start; i < end; i++){
		if(Arr[i] <= pivot){
			swap(&Arr[i],&Arr[pIndex]);
			pIndex++;
		}
	}
	swap(&Arr[pIndex], &Arr[end]);
	return pIndex;
}
void QuickSort(int Arr[], int start, int end){
	if(start < end){
		int pIndex = Partition(Arr, start, end);
		QuickSort(Arr,start,pIndex - 1);
		QuickSort(Arr,pIndex + 1, end);
	}
}
int main() {
	int Arr[] = {1, 4, 45, 6, 10, -8};
	int A = 16;
	if(hasTwoElements(Arr, 6, A))
		cout<<"Array has two elements with sum 16";
	else
		cout<<"Array doesn't have two elements with sum 16";
	return 0;
}