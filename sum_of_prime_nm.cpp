#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> simpleSieve(int A, vector<int> &sieve) {
    vector<int > primes;
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2; i <= A; i++) {
        if(sieve[i] == 1) {
            for(int j = 2; i * j <= A; j++) {
                sieve[i * j] = 0;
            }
            primes.push_back(i);
        }
    }
    return primes;
}

bool isPrime(int n, int A, vector<int> primes, vector<int> sieve) {
   if(n <= A) {
        return sieve[n] == 1 ? true : false;
    }
    int length = primes.size();
    for(int i = 0; i < length && primes[i] <= sqrt(n);  i++){
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}
void primesum(int A) {
    int sqrtOfA = sqrt(A);
    vector <int> sieve(sqrtOfA + 1, 1);

    vector<int> primes = simpleSieve(sqrtOfA, sieve);
    vector<int> ans;

    for(int i = 2; i <= A; ++i) {
        if(isPrime(i, sqrtOfA, primes, sieve) && isPrime(A - i, sqrtOfA, primes, sieve)) {
            ans.push_back(i);
            ans.push_back(A - i);
			cout<<i<<" "<<A-i<<endl;
			break;
        }
    }
    
}


int main() {
	primesum(89228404);
	return 0;
}