#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

void orangesRotting(int startNode, unordered_map<int, bool> &visited, vector<vector<int>> &grid){
    
}

int main(){
    int m,n;
    cout << "Ener value of m and n << endl";
    cin >> m >> n;

    vector<vector<int>> grid(m,n);

    cout << "Enter whether the value at the unit will be (0, 1 or 2)" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    unordered_map<int, bool> visited;

    cout << "No of oranges rotting" << endl;
    for(int i = 0; i < m; i++){
        if(!visited[i]){
            orangesRotting(i, visited, grid);
        }
    }
}