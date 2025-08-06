#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetWithDup(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
    result.push_back(temp);  // include current subset

    for (int j = i; j < nums.size(); j++) {
        // Skip duplicates
        if (j > i && nums[j] == nums[j - 1]) continue;

        temp.push_back(nums[j]);  // pick
        subsetWithDup(j + 1, nums, temp, result);  // recurse
        temp.pop_back();  // backtrack
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (can include duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Sort first to bring duplicates together
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> temp;

    subsetWithDup(0, nums, temp, result);

    cout << "Unique subsets are:\n";
    for (auto& subset : result) {
        cout << "[ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}