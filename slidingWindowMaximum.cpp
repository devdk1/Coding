#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    int n;
    cin>>n;

    int A[n];
    for(int i = 0; i < n; i++) 
        cin>>A[i];
    int k, i;
    cin>>k;

    deque<int> Q(k);
    for(i = 0; i < k; i++) {
        while (!Q.empty() && A[i] >= A[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for(;i < n; i++) {
        cout<<A[Q.front()]<<" ";

        // 1). Remove the elements which are not the part of window
        while(!Q.empty() && Q.front() <= (i - k)) {
            Q.pop_front();
        }
        // 2). Remove the elements which are not useful and are in window
        while(!Q.empty() && A[i] >= A[Q.back()]) {
            Q.pop_back();
        }
        // 3). Add the new element
        Q.push_back(i);
    }
    cout<<A[Q.front()]<<endl;
    return 0;
}