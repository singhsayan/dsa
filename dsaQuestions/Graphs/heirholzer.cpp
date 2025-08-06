#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

void hierholzer(int start, unordered_map<int, list<int>>& adj, vector<int>& path) {
    stack<int> st;
    st.push(start);

    while(!st.empty()) {
        int node = st.top();

        if(!adj[node].empty()) {
            int neighbor = adj[node].front();
            adj[node].pop_front();  // remove edge from node
            adj[neighbor].remove(node); // remove edge from neighbor
            st.push(neighbor);
        } else {
            path.push_back(node);
            st.pop();
        }
    }
}

int main() {
    int V, E;
    cout << "Enter total number of vertices and edges:" << endl;
    cin >> V >> E;

    unordered_map<int, list<int>> adj;
    vector<int> degree(V, 0);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int start = 0;
    // Find starting point
    for(int i = 0; i < V; i++) {
        if(degree[i] % 2 != 0) {
            start = i;
            break;
        }
    }

    vector<int> path;
    hierholzer(start, adj, path);

    cout << "Eulerian Path/Circuit is:" << endl;
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if(i != 0) cout << " -> ";
    }
    cout << endl;

    return 0;
}