#include<iostream>
using namespace std;
int main(){
    int arr[100];
    for(int i = 1; i <=100; i++){
        if((i % 5 == 0) && (i % 3 == 0))
         cout<<"FizzBuzz"<<" ";
        else if(i % 5 == 0)
         cout<<"Buzz"<<" ";
        else if(i % 3 == 0)
         cout<<"Fizz"<<" ";
        else 
         cout<<i<<" ";
    }
}