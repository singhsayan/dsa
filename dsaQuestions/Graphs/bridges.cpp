#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited,
         vector<int> &tin, vector<int> &low, int &timer, vector<pair<int,int>> &bridges) {
    
    visited[node] = true;
    tin[node] = low[node] = timer++;

    for(int neighbor : adj[node]){
        if(neighbor == parent) continue;

        if(!visited[neighbor]){
            dfs(neighbor, node, adj, visited, tin, low, timer, bridges);

            // update low of current node
            low[node] = min(low[node], low[neighbor]);

            // bridge condition
            if(low[neighbor] > tin[node]){
                bridges.push_back({node, neighbor});
            }
        }
        else{
            // back edge
            low[node] = min(low[node], tin[neighbor]);
        }
    }
}

int main(){
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> tin(n, -1), low(n, -1);
    vector<pair<int, int>> bridges;
    int timer = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, -1, adj, visited, tin, low, timer, bridges);
        }
    }

    cout << "Bridges in the graph are:" << endl;
    for(auto bridge : bridges){
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}