#include <iostream>
#include <vector>
using namespace std;

#define V 5

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }

    return true;
}

bool hamCycleUtil(vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (pos == V) {

        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1)) return true;

            path[pos] = -1;
        }
    }

    return false;
}

void printSolution(vector<int> &path) {
    for (int i = 0; i < V; i++) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl; 
}

bool hamCycle(vector<vector<int>> &graph) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists" << endl;
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph);
    return 0;
}