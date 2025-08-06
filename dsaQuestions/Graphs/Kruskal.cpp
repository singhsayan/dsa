#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findParent(int node, vector<int> &parent){
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionBySize(int u, int v, vector<int>&parent, vector<int> &size){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if(pu == pv) return;

    if(size[pu] > size[pv]){
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    else{
        parent[pu] = pv;
        size[pv] += size[pu];
    }
}

int main(){
    int n, e;
    cout << "Enter total number of nodes and edges:" << endl;
    cin >> n >> e;

    vector<vector<int>> edges;

    cout << "Enter edges (u, v, w):" << endl;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    vector<int> size(n, 1);

    for(int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;
    vector<vector<int>> mstEdges;

    for(auto edge: edges){
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(findParent(u, parent) != findParent(v, parent)){
            unionBySize(u, v, parent, size);
            mstWeight += w;
            mstEdges.push_back({u, v});
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n" << endl;
    for(auto it : mstEdges) {
        cout << it[0] << " - " << it[1] << endl;
    }

    cout << "\nTotal weight of MST is: " << mstWeight << endl;

    return 0;
}