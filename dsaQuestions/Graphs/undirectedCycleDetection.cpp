#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool cycleDetect(int node, unordered_map<int,bool>&visited, unordered_map<int,int>&parent, 
vector<vector<int>>&adj){
    visited[node] = true;

    for(auto neighbor: adj[node]){
        if(!visited[neighbor]){
            parent[neighbor] = node;
            if(cycleDetect(neighbor, visited, parent, adj)){
                return true;
            }
        }

        else if(parent[neighbor] != node) return true;
    }
    return false;
}

bool cycleDetectBFS(int node, unordered_map<int,bool>&visited, unordered_map<int,int>&parent,
    vector<vector<int>>&adj){
        queue<int> q;

        q.push(node);
        visited[node] = true;
        parent[node] = -1;

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(auto neighbor: adj[current]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }

                else if(neighbor != parent[current]) return true;
            }
        }
        return false;
    }

int main(){
    int n;
    cout << "Enter total no of nodes:" << endl;
    cin >> n;

    int e; 
    cout << "Enter total no of edges" << endl;
    cin >> e;

    vector<vector<int>> adj(n);

    cout << e <<  "" <<  "Enter edges (u, v)" << " " << endl;
    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    unordered_map<int, int> parent;

    bool cycleFound = false;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            parent[i] = -1;
            if(cycleDetect(i, visited, parent, adj)){
                cycleFound = true;
                break;
            }
        }
    }

    if(cycleFound) cout << "Cycle Present in the graph" << endl;
    else cout << "Cycle not present in the graph" << endl;

    return 0;
}