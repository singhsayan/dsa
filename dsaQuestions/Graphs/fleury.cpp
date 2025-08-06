#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<int, vector<int>> adj;

void removeEdge(int u, int v) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
}

void dfs(int v, unordered_map<int, bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, visited);
    }
}

int countReachable(int v) {
    unordered_map<int, bool> visited;
    dfs(v, visited);
    return visited.size();
}

bool isValidNextEdge(int u, int v) {
    if (adj[u].size() == 1) return true;

    int count1 = countReachable(u);
    removeEdge(u, v);
    int count2 = countReachable(u);
    adj[u].push_back(v);
    adj[v].push_back(u);
    return count1 == count2;
}

void printEulerPath(int u) {
    for (int v : adj[u]) {
        if (isValidNextEdge(u, v)) {
            cout << u << " -> " << v << endl;
            removeEdge(u, v);
            printEulerPath(v);
            break;
        }
    }
}

int findStartVertex(int V) {
    int start = 0, odd = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() % 2 != 0) {
            odd++;
            start = i;
        }
    }
    return start;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter edges (u v):";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = findStartVertex(V);
    cout << "Eulerian Path/Circuit:";
    printEulerPath(start);

    return 0;
}