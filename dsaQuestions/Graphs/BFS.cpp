#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

void bfs(int src, vector<vector<int>>&adj, unordered_map<int,bool>&visited){
    visited[src] = true;

    queue<int> q;

    q.push(src);

    while(!q.empty()){
        int current = q.front();
        cout << current << " " << endl;
        q.pop();

        for(auto neighbor: adj[current]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int n,e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter value of edges (u, v):" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    
    cout << "BFS for graph is:" << endl;
    bfs(0, adj, visited);

    return 0;
}