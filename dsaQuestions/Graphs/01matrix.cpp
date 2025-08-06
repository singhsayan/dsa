#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> result(m, vector<int>(n, -1)); // -1 as unvisited
    queue<pair<int, int>> q;

    // Step 1: Push all 0s into the queue
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                result[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Directions for top, down, left, right
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // Step 2: BFS
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy] : directions){
            int newX = x + dx;
            int newY = y + dy;

            if(newX >= 0 && newY >= 0 && newX < m && newY < n && result[newX][newY] == -1){
                result[newX][newY] = result[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return result;
}

int main(){
    int m, n;
    cout << "Enter matrix dimensions (m n): ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements (0 or 1):" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Output matrix:" << endl;
    for(auto row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}