#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void DFS(int startNode, unordered_map<int,bool>&visited, vector<vector<int>> &adj){
    visited[startNode] = true;
    cout << startNode << " ";


    for(auto neighbor: adj[startNode]){
        if(!visited[neighbor]){
            DFS(neighbor, visited, adj);
        }
    }
}

int main(){
    int n;
    cout << "Enter no of nodes";
    cin >> n;

    int e;
    cout << "Enter no of edges" << endl;
    cin >> e;

    unordered_map<int, bool> visited;

    vector<vector<int>> adj(n);

    cout << "Enter" << " " << e << "edges (u, v)" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "DFS Traversal: ";
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, visited, adj);
        }
    }
    cout << endl;
    return 0;
}