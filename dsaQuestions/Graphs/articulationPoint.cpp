#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &tin,
         vector<int> &low, vector<bool> &visited, int &timer, vector<bool> &isArticulation) {

    visited[node] = true;
    tin[node] = low[node] = timer++;
    int childCount = 0;

    for (auto neighbor : adj[node]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            dfs(neighbor, node, adj, tin, low, visited, timer, isArticulation);
            low[node] = min(low[node], low[neighbor]);

            // articulation condition for non-root node
            if (low[neighbor] >= tin[node] && parent != -1) {
                isArticulation[node] = true;
            }

            childCount++;
        } 
        else {
            // back edge
            low[node] = min(low[node], tin[neighbor]);
        }
    }

    // root node condition
    if (parent == -1 && childCount > 1) {
        isArticulation[node] = true;
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false), isArticulation(n, false);
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, tin, low, visited, timer, isArticulation);
        }
    }

    cout << "Articulation points are:" << endl;
    for (int i = 0; i < n; i++) {
        if (isArticulation[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}