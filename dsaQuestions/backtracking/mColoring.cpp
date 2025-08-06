#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int vertex, int n, int m, vector<int>& colors, vector<vector<int>>& adj, int colorToTry) {
    for (int j = 0; j < adj[vertex].size(); j++) {
        int neighbor = adj[vertex][j];
        if (colors[neighbor] == colorToTry) {
            return false;
        }
    }
    return true;
}

bool mColoring(int vertex, int n, int m, vector<int>& colors, vector<vector<int>>& adj) {
    if (vertex == n) {
        cout << "One valid coloring: ";
        for (int c : colors) cout << c << " ";
        cout << endl;
        return true;
    }

    for (int colorToTry = 1; colorToTry <= m; colorToTry++) {
        if (isSafe(vertex, n, m, colors, adj, colorToTry)) {
            colors[vertex] = colorToTry;

            if (mColoring(vertex + 1, n, m, colors, adj)) {
                return true;
            }

            colors[vertex] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter value of nodes and edges (u, v) present in the graph:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m;
    cout << "Enter value of m:" << endl;
    cin >> m;

    vector<int> colors(n, 0);

    if (!mColoring(0, n, m, colors, adj)) {
        cout << "No valid coloring possible with " << m << " colors." << endl;
    }

    return 0;
}
