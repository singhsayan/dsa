#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool countSubsequences(int i, vector<int>&arr, int k){
    if(i == arr.size()){
        return (k == 0) ? 1 : 0;
    }
    bool take = false;

    if(k >= arr[i]){
        take  = countSubsequences(i + 1, arr, k - arr[i]);
    }
    bool notTake = countSubsequences(i + 1, arr, k);

    return (take || notTake);
}

int main(){

    int n;
    cout << "Enter size of stack:" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements present in stack:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of sum you want to check:" << endl;
    cin >> k;    

    if(countSubsequences(0, arr, k)){
        cout << "Subsequence exists" << endl;
    }
    else{
        cout << "Subsequence doesn't exist" << endl;
    }

    return 0;
}