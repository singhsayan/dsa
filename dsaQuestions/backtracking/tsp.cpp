#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// TC - O(n² · 2ⁿ)

int tsp(int pos, int visited, vector<vector<int>>&graph, int n, vector<vector<int>>&dp){
    if(visited == (1 << n) - 1){
        return graph[pos][0];
    }

    if(dp[pos][visited] != -1) return dp[pos][visited];

    int minCost = INT_MAX;
    for(int city = 0; city < n; city++){
        if((visited & (1 << n)) == 0){
            int newVisited = visited | (1 << city);
            int cost = graph[pos][city] + tsp(pos + 1, newVisited, graph, n, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[pos][visited] = minCost;
}

int main(){
    int n;
    cout << "Enter total number of cities:" << endl;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter cost adjaceny matrix (Enter zero if no path):" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << tsp(0, 1, graph, n, dp);

    cout << "Minimum tour cost:" << result << endl;
}