#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &topoSort){
    visited[node] = true;
    for(auto &neighour: adj[node]){
        int nextNode = neighbour.first;
        if(!visited[nextNode]){
            dfs(nextNode, adj, visited, topoSort);
        }
    }
    topoSort.push(node);
}

vector<int> ShortestPath(int n, vector<vector<int>> &adj, int start){
    vector<bool> visited(n, false);
    stack<int> topoStack;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, topoStack);
        }
    }

    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    while(!topoStack.empty()){
        int node = topoStack.top();
        topoStack.pop();
        if(distance[node] != INT_MAX){
            for (auto& neighbor : adj[node]){
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (distance[node] + weight < distance[nextNode]){
                    distance[nextNode] = distance[node] + weight;
                }
            }
        }
    }
    return distance;
}


int main() {
    int n, m, start;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter the edges in the format (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight);
    }

    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> result = shortestPath(n, adj, start);

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << (result[i] == INT_MAX ? "INF" : to_string(result[i])) << endl;
    }

    return 0;
}