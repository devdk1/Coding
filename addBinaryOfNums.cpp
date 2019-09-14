/**
 * Given two integers, add their binary representation. 
 */
#include <iostream>
#include <iosfwd>


using namespace std;
#define SIZE 16

int* add(int x, int y) {
    int carry = 0;
    int n = SIZE;

    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        if(x & (1 << i)) { // x is one
            if(y & (1 << i)) { // y is one
                if(carry) {
                    arr[n - i - 1] = 1;
                }
                else {
                    arr[n - i - 1] = 0;
                    carry = 1;
                }
            }
            else // y is zero
            {
                if(carry) {
                    arr[n - i - 1] = 0;
                }
                else {
                    arr[n - i - 1] = 1;
                }
            }
        }
        else { // x is zero
            if(y & (1 << i)) { // y is one
                if(carry) {
                    arr[n - i - 1] = 0;
                }
                else {
                    arr[n - i - 1] = 1;
                }
            }
            else { // both are zero
                if(carry) {
                    arr[n - i - 1] = 1;
                    carry = 0;
                }
                else {
                    arr[n - i - 1] = 0;
                }
            }
        }
    }
    return arr;
}

int main(void) {
    int x, y;
    cin>>x>>y;
    
    // cout<<"Binary of x is : "<<bitset<16>(x)<<endl;
    // cout<<"Binary of y is : "<<bitset<16>(y)<<endl;
    cout<<"Binary addition is : ";

    int* arr = add(x, y);     
    for (unsigned i = 0; i < SIZE; i++)
        cout<<arr[i];
    cout<<endl;

	delete[] arr;

    return 0;
}