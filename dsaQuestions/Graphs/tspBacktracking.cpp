//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost = INT_MAX; // Store minimum cost

    void solve(int city, vector<vector<int>>& cost, vector<bool>& visited, int count, int cost_so_far) {
        int n = cost.size();
        
        // Base case: if all cities visited
        if (count == n && cost[city][0] != 0) {
            minCost = min(minCost, cost_so_far + cost[city][0]); // Return to starting city
            return;
        }

        // Try all cities
        for (int next = 0; next < n; next++) {
            if (!visited[next] && cost[city][next] != 0) {
                visited[next] = true;
                solve(next, cost, visited, count + 1, cost_so_far + cost[city][next]);
                visited[next] = false; // Backtrack
            }
        }
    }
    
    int tsp(vector<vector<int>>& cost) {
        // Code here
        int n = cost.size();
        vector<bool> visited(n, false);
        visited[0] = true; // Start from city 0
        solve(0, cost, visited, 1, 0);
        return minCost;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.tsp(cost);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends