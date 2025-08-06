#include<iostream>
#include<vector>
using namespace std;

int countSubsequences(int i, vector<int>& arr, int k){
    if(i == arr.size()){
        return (k == 0) ? 1 : 0;
    }

    int count = 0;

    if(k >= arr[i]){
        count += countSubsequences(i + 1, arr, k - arr[i]); 
    }
    count += countSubsequences(i + 1, arr, k); 

    return count;
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

    cout << "Number of subsequences with sum as k:" << endl;
    cout << countSubsequences(0, arr, k) << endl;

    return 0;
}