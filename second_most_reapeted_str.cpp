#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        unordered_map<string, int> mymap; 
        string result, prev_str;       
        for(int i = 0; i < n; i++) {
            string str;
            cin>>str;

            mymap[str]++;
        }
        int first_max = INT_MIN, second_max = INT_MIN;
        for (unordered_map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
            // cout << it->first << " => " << it->second << '\n';
            if (it->second > first_max)
            {
                second_max = first_max;
                first_max  = it->second;
                result = prev_str;
                prev_str = it->first;
            }
            else if (it->second > second_max && it->second != first_max){
                second_max = it->second;
                result = it->first;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
