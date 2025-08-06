#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &adj, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if (distance + weight < dist[adjNode]) {
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> Distance: " << dist[i] << "\n";
    }
}

int main() {
    int n, e;
    cout << "Enter total number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n); // node -> {neighbor, weight}

    cout << "Enter edges in format (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if undirected
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(src, adj, n);

    return 0;
}