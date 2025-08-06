#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void topoSort(int node, unordered_map<int,bool>&visited, vector<vector<int>>&revGraph, stack<int>&s){
    visited[node] = true;

    for(auto neighbor: revGraph[node]){
        if(!visited[neighbor]){
            topoSort(neighbor, visited, revGraph, s);
        }
    }

    s.push(node);
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges" << endl;
    cin >> n >> e;

    vector<vector<int>> graph(n);
    vector<vector<int>> revGraph(n);

    cout << "Enter edges (u, v)" << endl;
    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u); 
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            topoSort(i, visited, revGraph, s);
        }
    }

    vector<int> safeNodes;
    while(!s.empty()){
        safeNodes.push_back(s.top());
        s.pop();
    }

    sort(safeNodes.begin(), safeNodes.end()); 

    cout << "Safe nodes are:" << endl;
    for(int node : safeNodes){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}