#include <iostream>
using namespace std;

void slidingWindowSum(int A[], int n, int sum) {
    int w_sum = 0;
    int len = INT_MAX;
    int start = 0, end = 0, j = 0;
    for(int i = 0; i < n;) {
        if(w_sum == sum) {
            if(len > (j - i)) {
                len = j - i;
                start = i;
                end = j - 1;
            }
            w_sum -= A[i];
            i++;
        }
        else if(w_sum > sum) {
            w_sum -= A[i];
            i++;
        }
        else if (w_sum < sum)
        {
            w_sum += A[j];
            j++;
        }
    }
    cout<<"From -> "<<start<<", To -> "<<end<<", of length -> "<<len<<endl;
}

int main(void) {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int k;
    cin>>k;

    slidingWindowSum(arr, n, k);
    return 0;
}
