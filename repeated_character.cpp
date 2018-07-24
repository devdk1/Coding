#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int t, i;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int len = str.length();
        map<char,int> map;
        for(i = 0; i < len; i++) 
            map[str[i]]++;
        for(i = 0; i < len; i++) {
            if(map[str[i]] > 1) {
                cout<<str[i]<<endl;
                break;
            }
        }
        if(i == len)
            cout<<"-1"<<endl;
    }
    return 0;
}
