#include <iostream>

using namespace std;

int missingNumber(int arr[], int n) {
  int total = ((n + 1) * (n + 2)) / 2;
  for(int i = 0; i < n; i++)
    total -= arr[i];
  return total;
}

/*
* Using XOR
*  1) XOR all the array elements, let the result of XOR be X1.
*  2) XOR all numbers from 1 to n, let XOR be X2.
*  3) XOR of X1 and X2 gives the missing number.
*/
int missingNumberByXor(int arr[], int n) {
  int i;
  int x1 = arr[0];
  int x2 = 1;
  for(i = 1; i < n; i++)
    x1 ^= arr[i];
  for(i = 2; i <= n + 1; i++)
    x2 ^= i;
  return x1 ^ x2;
}

int main(void) {
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n; i++)
    cin>>arr[i];

  cout<<"Missing number is : "<<missingNumberByXor(arr, n)<<endl;
  return 0;
}