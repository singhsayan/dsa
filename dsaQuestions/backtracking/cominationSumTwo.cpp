#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function
void candidates(int i, vector<int>& arr, int target, vector<int>& temp, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(temp);
        return;
    }

    if (i == arr.size()) return;

    for (int j = i; j < arr.size(); j++) {
        // Skip duplicates at the same level
        if (j > i && arr[j] == arr[j - 1]) continue;

        if (arr[j] > target) break; // No need to continue if current number exceeds target

        temp.push_back(arr[j]);
        candidates(j + 1, arr, target - arr[j], temp, result);  // j+1 because each number is used at most once
        temp.pop_back(); // backtrack
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements in array (can include duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter target sum: ";
    cin >> k;

    sort(arr.begin(), arr.end()); 

    vector<vector<int>> result;
    vector<int> temp;

    candidates(0, arr, k, temp, result);

    cout << "Unique combinations with given sum:" << endl;
    if (result.empty()) {
        cout << "No combinations found." << endl;
    } 
    else {
        for (const auto& vec : result) {
            for (int num : vec) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}