#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

ool canPartition(int index, vector<int>& arr, vector<int>& subsetSum, int k, int target) {
    if(index == arr.size()) {
        for(int i = 0; i < k; i++) {
            if(subsetSum[i] != target) return false;
        }
        return true;
    }

    for(int i = 0; i < k; i++) {
        if(subsetSum[i] + arr[index] <= target) {
            subsetSum[i] += arr[index];
            if(canPartition(index + 1, arr, subsetSum, k, target)) return true;
            subsetSum[i] -= arr[index];
        }

        if(subsetSum[i] == 0) break;
    }

    return false;
}

bool subsetSum(int n, int k, vector<int>&arr){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    if(sum % k != 0) return false;

    sort(arr.begin(), arr.end(), greater<int>());
    if(arr[0] > target) return false;

    vector<int> subsetSum(k, 0);
    return canPartition(0, arr, subsetSum, k, target);

}

int main(){
   int n;
   cout << "Enter size of array:" << endl;
   cin >> n;

   vector<int> arr(n);
   cout << "Enter values in array:" << endl;
   for(int i = 0; i < n; i++){
    cin >> arr[i];
   }

   int k;
   cout << "Enter in how many parts to partition:" << endl;
   cin >> k;

   if(subsetSum(n, k, arr)){
    cout << "Subsets exists:" << endl;
   }
   else{
    cout << "Subset doesn't exists:" << endl;
   }
   
   return 0;
}