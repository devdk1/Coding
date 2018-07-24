#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin, str);
        int n = str.length();
        for(int i = 0; i < n; i++) {
            if(i == 0)
                str[i] = toupper(str[i]);
            else if(str[i] == ' ')
                str[i + 1] = toupper(str[i + 1]);
        }
        for(int i = 0; i < n; i++) 
            cout<<str[i];
        cout<<endl;
    }
	return 0;
}