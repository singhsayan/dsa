#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, st, adj);
        }
    }

    st.push(node);  // push when finished
}

void revDfs(int node, unordered_map<int, bool> &visited, vector<vector<int>> &revAdj, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor]) {
            revDfs(neighbor, visited, revAdj, component);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: " << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u, v): " << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    // Step 1: DFS and store in stack based on finish time
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> revAdj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            revAdj[v].push_back(u);
        }
    }

    // Step 3: Do DFS using stack order on reversed graph
    visited.clear();
    cout << "\nStrongly Connected Components are:" << endl;
    while (!st.empty()) {
        int topNode = st.top();
        st.pop();

        if (!visited[topNode]) {
            vector<int> component;
            revDfs(topNode, visited, revAdj, component);

            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}