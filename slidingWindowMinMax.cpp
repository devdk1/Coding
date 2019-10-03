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
    int sum = 0;

    deque<int> Q_min(k), Q_max(k);
    
    for(i = 0; i < k; i++) {
        while(!Q_max.empty() && A[i] >= A[Q_max.back()])
            Q_max.pop_back();
        while(!Q_min.empty() && A[i] <= A[Q_min.back()])
            Q_min.pop_back();
        Q_max.push_back(i);
        Q_min.push_back(i);
    }

    for(; i < n; i++) {
        sum += A[Q_max.front()] + A[Q_min.front()];

        // 1). Remove elements which are not part of current window
        while(!Q_max.empty() && Q_max.front() <= i - k)
            Q_max.pop_front();
        while(!Q_min.empty() && Q_min.front() <= i - k)
            Q_min.pop_front();

        // 2). Remove elements which are not useful and are in window
        while(!Q_max.empty() && A[i] >= A[Q_max.back()])
            Q_max.pop_back();
        while(!Q_min.empty() && A[i] <= A[Q_min.back()])
            Q_min.pop_back();
        Q_max.push_back(i);
        Q_min.push_back(i);
    }
    sum += A[Q_max.front()] + A[Q_min.front()];
    cout<<sum<<endl;
    return 0;
}