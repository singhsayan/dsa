#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> kahn(int n , vector<vector<int>>&adj){
        queue<int> q;
        vector<int> result;
        vector<int> indegree(n + 1, 0);

        for(int u = 1; u <= n; u++){
            for(int v : adj[u]){
                indegree[v]++;
            }
        }

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int current = q.front();
            q.pop();
            result.push_back(current);

            for(auto neighbor: adj[current]){
                indegree[neighbor]--;

                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        if(result.size() != n) return {};

        return result;
    }

int main(){
    int n, e;
    cout << "Enter total number of nodes and  edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    cout << "Enter value of edges (u, v)" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    unordered_map<int,bool>visited;
    vector<int> result =  kahn(n, adj);

    if (result.empty()) {
        cout << "Cycle detected, topological sort not possible!" << endl;
    } 
    else {
        cout << "Topological order traversal is:" << endl;
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    };
    return 0;
}