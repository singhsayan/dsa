#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    set<pair<int, int>> st; // {distance, node}
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {
        auto it = *(st.begin());
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if(dist[adjNode] > d + weight) {
                if(dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = d + weight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n); // {node, weight}

    cout << "Enter value of edges (u, v, w)" << endl;
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this if directed
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    vector<int> dist(n, 1e9);

    dijkstra(src, n, adj, dist);

    cout << "Shortest distance from source node " << src << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if(dist[i] == 1e9) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}