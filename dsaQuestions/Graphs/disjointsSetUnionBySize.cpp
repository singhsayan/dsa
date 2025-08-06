#include<iostream>
#include<vector>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &size, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int findParent(int node, vector<int> &parent){
    if(parent[node] == node) return node;

    return parent[node] = findParent(parent[node], parent); 
}

void unionBySize(int u, int v, vector<int> &parent, vector<int> &size){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if(pu == pv) return;

    if(size[pu] < size[pv]){
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    else{
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}

int main(){
    int n;
    cout << "Enter number of nodes:" << endl;
    cin >> n;

    vector<int> parent(n);
    vector<int> size(n);

    makeSet(parent, size, n);

    int q;
    cout << "Enter total union operations:" << endl;
    cin >> q;

    cout << "Enter union pairs (u v):" << endl;
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        unionBySize(u, v, parent, size);
    }

    cout << "Final parent of each node:" << endl;
    for(int i = 0; i < n; i++){
        cout << "Node " << i << " -> Parent: " << findParent(i, parent) << endl;
    }

    return 0;
}