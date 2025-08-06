#include<iostream>
#include<vector>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> inc(n, 1), dec(n, 1);

    // Calculate LIS for each index
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // Calculate LDS from each index
    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(arr[i] > arr[j]){
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int maxBitonic = 0;
    for(int i = 0; i < n; i++){
        if(inc[i] > 1 && dec[i] > 1){
            maxBitonic = max(maxBitonic, inc[i] + dec[i] - 1);
        }
    }

    return maxBitonic;
}

int main(){
    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int result = longestBitonicSubsequence(arr);
    cout << "Maximum Length of Bitonic Subsequence is:" << endl;
    cout << result << endl;

    return 0;
}