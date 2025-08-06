#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool cycleDetect(int node, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsVisited,
    vector<vector<int>>& adj) {

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (cycleDetect(neighbor, visited, dfsVisited, adj))
                return true;
        } else if (dfsVisited[neighbor]) {
            return true;  // Back edge found
        }
    }

    dfsVisited[node] = false; // Remove from recursion stack
    return false;
}

int main() {
    int n, e;
    cout << "Enter total number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Directed edge
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (cycleDetect(i, visited, dfsVisited, adj)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Cycle detected in the graph" << endl;
    else
        cout << "No cycle in the graph" << endl;

    return 0;
}