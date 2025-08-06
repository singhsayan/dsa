#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void prim(int n, vector<vector<pair<int, int>>>& adj, vector<int>& parent, vector<int>& key, vector<bool>& mstSet) {
    key[0] = 0; // Start from node 0
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int minKey = INT_MAX;
        int u = -1;

        // Find the node with the minimum key not yet in MST
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        // Update the key values of adjacent vertices
        for (auto [v, weight] : adj[u]) {
            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter total number of nodes and edges present:" << endl;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n);
    
    cout << "Enter value of edges and their respective weights (u, v, w)" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    prim(n, adj, parent, key, mstSet);

    cout << "\nEdges in the Minimum Spanning Tree are:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (weight = " << key[i] << ")" << endl;
    }

    return 0;
}