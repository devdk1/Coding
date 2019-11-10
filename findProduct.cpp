#include <iostream>
using namespace std;

void findProduct(int A[], int n) {
    int left[n], right[n];
    
    left[0] = 1;
    for(int i = 1; i < n; i++)
        left[i] = A[i - 1] * left[i - 1];

    right[n - 1] = 1;
    for(int j = n - 2; j >= 0; j--)
        right[j] = A[j + 1] * right[j + 1];

    for(int i = 0; i < n; i++) 
        A[i] = left[i] * right[i];
}

int main(void) {
    int n;
    cin>>n;
    int A[n];

    for(int i = 0; i < n; i++) 
        cin>>A[i];
    findProduct(A, n);

    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

