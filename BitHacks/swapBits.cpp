#include <iostream>

using namespace std;

int swapBits(int n, int p, int q) {
    if(((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q)) {
        n = n ^ (1 << p);
        n = n ^ (1 << q);
    }
    return n;
}

int main() {
    int n ,p ,q;
    cin>>n>>p>>q;
    cout<<"Number after swapping bits : "<<swapBits(n, p, q)<<endl;
    return 0;
}