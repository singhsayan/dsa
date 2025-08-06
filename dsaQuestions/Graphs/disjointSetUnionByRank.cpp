#include<iostream>
#include<vector>
#include<uonrdered_mp>
using namespace std;


void makeset(int n, vector<int>&parent, vector<int>&rank){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int>&parent){
    if(parent[[node] == node]) return node;

    return parent[node] = findParent(parent[node], parent);
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if(pu == pv) return;

    if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    }

    else if(rank[pv] < rank[pu]){
        parent[pv] = pu;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }
}   

int main(){
    int n;
    cout << "Enter total number of nodes:" << endl;
    cin >> n;

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(n, parent, rank);

    cout << "Enter total number of union operations:" << endl;
    int q;
    cin >> q;

    cout << "Enter union pairs (u, v):" << endl;
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        unionByRank(u, v, parent, rank);
    }

    cout << "Final parent of each node:" << endl;
    for(int i = 0; i < n; i++){
        cout << "Node " << i << " -> Parent: " << findParent(i, parent) << endl;
    }
    cout << endl
    return 0;
}