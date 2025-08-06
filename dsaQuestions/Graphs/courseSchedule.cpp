#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> topoSort(int numCourses, vector<vector<int>> &prequesties){
    vector<int> result;
    vector<int> indegree(numCourses, 0);
    queue<int> q;

    for(int u = 0; u < numCourses; u++){
        for(int v: prequesties[u]){
            indegree[v]++;
        }
    }

    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();
        result.push_back(current);

        for(auto neighbor: prequesties[current]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }

    if(result.size() != numCourses) return {};

    return result;
}

int main(){
    int numCourses, e;
    cout << "Enter total number of nodes and edges" << endl;
    cin >> numCourses >> e;

    vector<vector<int>> prequesties(numCourses);

    cout << "Enter the value of edges (u, v)" << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        prequesties[u].push_back(v);
    }

    vector<int> result = topoSort(numCourses, prequesties);


    if(!result.size()){
        cout << "False! We cannot finish all the courses." << endl;
    }
    else{
        cout << "True! We can finish all the courses." << endl;
    }

    return 0;
}