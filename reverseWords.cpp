#include <iostream>
using namespace std;

void reverse(char s[], int l, int r) {
    while(l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

void reverseWords(char s[], int n) {
    int j = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n|| s[i] == '.') {
            reverse(s, j, i - 1);
            j = i + 1;
        }
    }
    reverse(s, 0, n - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        char s[n];
        for(int i = 0; i < n; i++)
            cin >> s[i];

        reverseWords(s, n);
        for(int i = 0; i < n; i++)
            cout<<s[i];
        cout<<endl;
    }
}