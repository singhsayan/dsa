#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

void dfs(int curr, unordered_map<int,bool>&visited, vector<vector<int>>&adj, stack<int>&s){
    visited[curr] = true;

    for(auto neighbor: adj[curr]){
        if(!visited[neighbor]){
            dfs(neighbor, visited, adj, s);
        }
    }
    s.push(curr);
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>>adj(n + 1);

    cout << "Enter value of edges (u,v):" << endl;
    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    stack<int>s;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, visited, adj, s);
        }
    }

    cout << "Valid topological sort is:" << endl;
    while(!s.empty()){
        cout << s.top() << " " << endl;
    }
    cout << endl;

    return 0;
}