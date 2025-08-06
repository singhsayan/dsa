#include<iostream>
#include<vector>
using namespace std;

vector<int> bellmanFord(int src, vector<vector<int>> &adj, vector<int> &distance, int n){
    distance[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(auto neighbor: adj){
            int u = neighbor[0];
            int v = neighbor[1];
            int wt = neighbor[2];

            if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }

    for(auto neighbor: adj){
        int u = neighbor[0];
        int v = neighbor[1];
        int wt = neighbor[2];

        if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
            return {-1};
        }
    }

    return distance;
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj; 

    cout << "Enter value of edges (u, v, w)" << endl;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }

    int src;
    cout << "Enter source node:" << endl;   
    cin >> src;

    vector<int> distance(n, 1e8); 

    vector<int> result = bellmanFord(src, adj, distance, n);

    if(result[0] == -1){
        cout << "Negative weight cycle detected." << endl;
    } 
    else {
        cout << "Shortest distances from source node " << src << " are:" << endl;
        for(int i = 0; i < n; i++){
            cout << "Node " << i << ": " << result[i] << endl;
        }
    }

    return 0;
}