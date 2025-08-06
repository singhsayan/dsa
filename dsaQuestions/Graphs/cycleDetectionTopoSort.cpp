#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

bool dfs(int curr, unordered_map<int,bool>&visited, unordered_map<int,bool>&recStack, vector<vector<int>>&adj, stack<int>&s){
    visited[curr] = true;
    recStack[curr] = true;

    for(auto neighbor: adj[curr]){
        if(!visited[neighbor]){
            if(dfs(neighbor, visited, recStack, adj, s))
                return true;  // Cycle found in deeper call
        } else if(recStack[neighbor]){
            return true;  // Cycle found (back edge)
        }
    }

    recStack[curr] = false; // Done processing this node
    s.push(curr); // Safe to include in topo sort
    return false;
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    cout << "Enter value of edges (u,v):" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> recStack;
    stack<int> s;

    bool hasCycle = false;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i, visited, recStack, adj, s)){
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle){
        cout << "Cycle is present in the graph." << endl;
    } else {
        cout << "Valid topological sort is:" << endl;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    return 0;
}