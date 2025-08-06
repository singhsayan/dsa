#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction){
        // direction 0 - undirected
        // direction 1 = directed

        // create an edge from u to v 
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void bfs(vector<vector<int>> &adj){
        unordered_map<int, bool> visited;
        queue<int>q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int frontNode = q.top();
            q.pop();
            cout << frontNode << " ";

            for(auto neighbour: adj[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(int node , vector<vector<int>> &adj, vector<int> &result, unordered_map<int, bool>& visited){
        result.push_back(node);
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited(neighbour)){
                dfs(neighbour,adj,result,visited);
            }
        }

    }
    vector<int> dfsOfGraph(vector<vector<int>> adj){
        unordered_map<int, bool> visited;
        vector<int> result;
        
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]{
                dfs(i,adj,result,visited);
            })
        }
        return result;
    }

    vector<int> toposort(vector<vector<int>> &adj, int node, stack<int> &s, vector<int> &ans ){
        visited[node] = true;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                toposort(adj,neighbour,s,ans);
            }
        }
        s.push(node);
    }

    vector<int> topoSort(vector<vector<int>> adj, int v){
        unordered_map<int, bool> visited;
        stack<int> s;
        vector<int> ans;

        for(int i = 0; i < v; i++){
            if(!visited[i]){
                toposort(adj,i,visited,s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }

    bool isCyclic(int v, vector<vector<int>> adj){
        vector<int> inDegree(v,0);

        for(int i = 0; i < adj.size(); i++){
            for(int neighbour: adj[i]){
                inDegree[neighbour]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < adj.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node = q.top();
            q.pop();
            count++;

            for(int neighbor : adj[node]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return (count != v);
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first << "-> " << endl;
            for(auto j: i.second){
                cout << j << ","
            }
            cout << endl;
        }
    }
};

int main() {
    int m;
    cout << "Enter total number of edges: ";
    cin >> m;

    int n;
    cout << "Enter total number of nodes: ";
    cin >> n;

    Graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // Printing the graph
    cout << "\nAdjacency List of the Graph:\n";
    g.printAdjList();

    // Example BFS and DFS calls
    vector<vector<int>> adj(n);
    for (auto i : g.adj) {
        for (auto j : i.second) {
            adj[i.first].push_back(j);
        }
    }

    cout << "\nBFS Traversal starting from node 0: ";
    g.bfs(adj);

    cout << "\nDFS Traversal starting from node 0: ";
    vector<int> dfsResult = g.dfsOfGraph(adj);
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}