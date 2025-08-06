#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& arr, vector<int>& subsetSum, vector<bool>& taken, int index, int k, int target) {
    int n = arr.size();

    if (subsetSum[index] == target) {
        if (index == k - 1) return true; // all subsets done
        return canPartition(arr, subsetSum, taken, index + 1, k, target);
    }

    for (int i = 0; i < n; i++) {
        if (!taken[i] && subsetSum[index] + arr[i] <= target) {
            taken[i] = true;
            subsetSum[index] += arr[i];

            if (canPartition(arr, subsetSum, taken, index, k, target)) return true;

            taken[i] = false;
            subsetSum[index] -= arr[i];
        }
    }
    return false;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements in array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter value of k: ";
    cin >> k;

    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[i];

    if (k == 0 || totalSum % k != 0) {
        cout << "Subset doesn't exist." << endl;
        return 0;
    }

    int target = totalSum / k;
    vector<int> subsetSum(k, 0);
    vector<bool> taken(n, false);

    if (canPartition(arr, subsetSum, taken, 0, k, target)) {
        cout << "Subset exists." << endl;
    } else {
        cout << "Subset doesn't exist." << endl;
    }

    return 0;
}
