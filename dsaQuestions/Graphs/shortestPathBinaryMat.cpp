#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int shortestPath(int i, int j, vector<vector<int>>&mat){
    int n = mat.size();

    if(mat[i][j] != 0 || mat[n - 1][n - 1] != 0) return -1;

    queue<pair<int, int>> q;

    vector<pair<int,int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    q.push({i, j});
    
    int length = 1;

    while(!q.empty()){
        int size = q.size();

        while(size--){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(auto [dx, dy]: directions){
                int newX = x + dx;
                int newY = y + dy;

                if(newX == n - 1 && newY == n - 1){
                    return length + 1;
                }

                if(newX >= 0 && newY >= 0 && newX < n && newY < n &&  mat[newX][newY] == 0){
                    q.push({newX, newY});
                    mat[newX][newY] = 1;
                }
            }
        }
        length++;
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter value of n:" << endl;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Fill the grid with (0, 1) value" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int shortestDistance = shortestPath(0, 0, mat);
    cout << "Shortest length is:" << shortestDistance << endl;
    return 0;
}