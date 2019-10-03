#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin>>n;

    vector<int> least_primes(n + 1, 0);
    least_primes[1] = 1;

    for(int i = 2; i <= n; i++) {
        if(least_primes[i] == 0) {
            least_primes[i] = i;
            for(int j = 2 * i; j <= n; j += i) {
                if(least_primes[i] == 0)
                    least_primes[j] = i;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout<<"least prime factors of "<<i<<" is "<<least_primes[i]<<endl;
    }
    return 0;
}