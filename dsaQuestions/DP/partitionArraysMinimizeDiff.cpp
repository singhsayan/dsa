#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = accumulate(arr.begin(), arr.end());

    int absdiff = 

    return 0;
}