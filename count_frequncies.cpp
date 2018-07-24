#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    // std::map< int, int > occurances;
    int count[n];      
    for(int i = 0; i < n; i++){    
        count[i] = 0;
        count[arr[i] - 1]++;
    }
    
    for(int i = 1; i <= n; i++)
        cout<<i<<" -> "<<count[i-1]<<endl;
    // std::map< int, int >::iterator iter;
    // for ( iter = occurances.begin(); iter != occurances.end(); ++iter )
    //     std::cout << iter->first << "-> " << iter->second << '\n';
}