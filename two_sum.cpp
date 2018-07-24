#include <iostream>
#include <unordered_map>
using namespace std;

void twoSum(int arr[], int size, int target) {
    unordered_map<int, int> map;
    int i;
    for(i = 0; i < size; i++) {
        int num_to_find = target - arr[i];
        map[arr[i]] = i;
        if(map.find(num_to_find) != map.end()){
            cout<<"First Number is at position "<<map[num_to_find] + 1<<endl;
            cout<<"Second Number is at position "<<i + 1<<endl;
            break;
        }
    }
    if(i == size)
        cout<<"Not match"<<endl;
}

int main() {
    int n, target_num;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>target_num;
    twoSum(arr, n, target_num);
}

