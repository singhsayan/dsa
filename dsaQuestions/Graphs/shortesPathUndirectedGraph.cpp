#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

void shortestPath(int src, int dest, vector<vector<int>> &adj, 
    unordered_map<int,bool>&visited, unordered_map<int, int>&parent, vector<int>&result){
    
    queue<int> q;

    visited[src] = true;
    parent[src] = -1;
    q.push(src);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == dest) break;

        for(auto neighbor: adj[current]){
            if(!visited[neighbor]){
                parent[neighbor] = current;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    int node = dest;
    while(node != -1){
        result.push_back(node);
        node = parent[node];
    }

    reverse(result.begin(), result.end());
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    int src, dest;
    cout << "Enter source and destination node:" << endl;
    cin >> src >> dest;

    vector<vector<int>> adj(n);

    cout << "Enter value of edges (u, v)" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    vector<int> result;
    
    shortestPath(src, dest, adj, visited, parent, result);

    cout << "Shortest path from " << src << " to " << dest << " is: ";
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}