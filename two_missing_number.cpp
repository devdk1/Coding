#include <iostream>
using namespace std;

void findTwoMissingNumbers(int arr[], int n) {
    int XOR = arr[0];
    //XOR of all elements of array
    for(int i  = 1; i < n - 2; i++)
        XOR ^= arr[i];
    //Getting XOR of all elements in range
    for(int i = 1; i <= n; i++)
        XOR ^= i;
    // XOR has xor of missing elements
    // Any set bit in it must be set in one missing and unset in other missing number
    // Get a set bit of XOR (gives the rightmost set bit)
    int set_bit_no = XOR & ~(XOR-1);
    int x = 0, y = 0; // Initialize missing numbers
    for (int i = 0; i < n-2; i++) {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i]; /*XOR of first set in arr[] */
        else
            y = y ^ arr[i]; /*XOR of second set in arr[] */
        }
        for (int i = 1; i <= n; i++)
        {
        if (i & set_bit_no)
            x = x ^ i; /* XOR of first set in arr[] and
                        {1, 2, ...n }*/
        else
            y = y ^ i; /* XOR of second set in arr[] and
                        {1, 2, ...n } */
    }
    cout<<"Two Missing Numbers are : "<<x<<" "<<y<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        int arr[len];
        for(int i = 0; i < len; i++) {
            cin>>arr[i];
        }
        findTwoMissingNumbers(arr, len + 2);
    }
    return 0;
}