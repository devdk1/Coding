#include <iostream>
#include <cmath>
using namespace std;

int main() {
    /*
        m => No. of companies
        n => No. of shortlisted students
        t => Interview time for each company
        s => shortlisted students per company
    */
    int m, n, t, s;
    cout<<"Enter the No. of companies : ";
    cin>>m;
    cout<<"Enter the No. of total shortlisted students : ";
    cin>>n;
    cout<<"Enter the Interview time for each company (in hours) : ";
    cin>>t;

    int students_per_company[m], c_max = INT_MIN, s_max = INT_MIN;
    for(int i = 0; i < m; i++) {
        cout<<"Enter the number of shortlisted students for Company C"<<i+1<<endl;
        int s;
        cin>>s;
        students_per_company[i] = s;
    }
    for(int i = 0; i < m; i++) 
        c_max = (students_per_company[i] > c_max) ? students_per_company[i] : c_max;
    for(int i = 0; i < m; i++) {
        int c_priority[students_per_company[i]], c_scores[students_per_company[i]], scores = c_max * 10;
        cout<<"Enter student priority for company C"<<i+1<<" : ";
        for(int j = 0; j < students_per_company[i]; j++) {
            cin>>c_priority[j];
            c_scores[j] = scores;
            scores -= 10;
        }
        
    }
    for(int i = 0; i < m; i++)
        cout<<"C"<<i+1<<"  "<<students_per_company[i]<<endl;
}