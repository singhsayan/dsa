#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void tspBacktrack(int node, int costSoFar, int count, int n, vector<vector<int>>& graph,
                  vector<bool>& visited, int& minCost, int start) {

    if (count == n && graph[node][start] != 0) {
        minCost = min(minCost, costSoFar + graph[node][start]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[node][i] != 0) {
            visited[i] = true;
            tspBacktrack(i, costSoFar + graph[node][i], count + 1, n, graph, visited, minCost, start);
            visited[i] = false; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter number of cities (nodes): ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter cost matrix (0 if no direct path):" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    int minCost = INT_MAX;

    visited[0] = true;
    tspBacktrack(0, 0, 1, n, graph, visited, minCost, 0);

    cout << "Minimum cost to visit all cities and return to start: " << minCost << endl;
    return 0;
}