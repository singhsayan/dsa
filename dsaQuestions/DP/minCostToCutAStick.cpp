#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int minCost(int i, int j, vector<int>&cuts, vector<vector<int>>&dp){
    if(i+1 >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int minimumCost = INT_MAX;
    for(int k = i + 1; k < j; k++){
        int cost = cuts[j] - cuts[i] +  minCost(i, k, cuts, dp) + minCost(k, j, cuts, dp);
        minimumCost = min(minimumCost, cost);
    }

    return dp[i][j] = minimumCost;
}

int main(){
    int n;
    cout << "Enter length of stick:" << endl;
    cin >> n;

    int x;
    cout << "Enter length of array:" << endl;
    cin >> x;

    vector<int> cuts(x);

    cout << "Enter elements present in array:" << endl;
    for(int i = 0; i < x; i++){
        cin >> cuts[i];
    }

    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());

    int m = cuts.size();

    vector<vector<int>> dp(m, vector<int>(m, -1));

    cout << "Minimum cost to cut a stick is:" << endl;
    cout << minCost(0, m - 1, cuts, dp);

    return 0;
}