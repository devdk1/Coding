#include<iostream>
#include<string>
using namespace std;
int main()
 {
    int t, i, j;
    cin>>t;
    while(t--) {
        string str_1, str_2, result = "";
        cin>>str_1>>str_2;;
        int f_len = str_1.length();
        int l_len = str_2.length();
        int i = j = 0;
        while(i < f_len && j < l_len) {
            result += str_1[i];
            result += str_2[j];
            i++;
            j++;
        }
        while(i < f_len)
            result += str_1[i++];
        while(j < l_len)
            result += str_2[j++];
        cout<<result<<endl;
    }
	return 0;
}