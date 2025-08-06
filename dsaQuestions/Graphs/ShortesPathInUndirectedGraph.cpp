#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> &edges, int start, int target) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX); // To store shortest distances
    vector<int> parent(n, -1);   // To reconstruct the path
    vector<bool> visited(n, false); // To track visited nodes

    queue<int> q;
    dist[start] = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) { // Check for unvisited nodes
                visited[neighbour] = true;
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    vector<int> path;
    if (dist[target] == INT_MAX) {
        return path; // No path exists
    }

    // Reconstruct the path from target to start using parent array
    int currentNode = target;
    while (currentNode != -1) {
        path.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    reverse(path.begin(), path.end()); // Reverse to get path from start to target
    return path;
}