#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int matrixChain(int i, int j, vector<int>& arr, vector<vector<int>>& dp, vector<vector<int>>& split) {
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;

    for(int k = i; k < j; k++) {
        int cost = matrixChain(i, k, arr, dp, split) +
                   matrixChain(k + 1, j, arr, dp, split) +
                   arr[i - 1] * arr[k] * arr[j];

        if(cost < minCost) {
            minCost = cost;
            split[i][j] = k; // 📌 store the partition index
        }
    }

    return dp[i][j] = minCost;
}

// 🧾 Function to print optimal parenthesization
void printParenthesis(int i, int j, vector<vector<int>>& split) {
    if(i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printParenthesis(i, split[i][j], split);
    printParenthesis(split[i][j] + 1, j, split);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter number of matrices + 1 (i.e., size of dimension array): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter dimension array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> split(n, vector<int>(n, -1)); // 🆕

    int minMultiplications = matrixChain(1, n - 1, arr, dp, split);

    cout << "Minimum number of multiplications needed: " << minMultiplications << endl;

    cout << "Optimal parenthesization: ";
    printParenthesis(1, n - 1, split);
    cout << endl;

    return 0;
}