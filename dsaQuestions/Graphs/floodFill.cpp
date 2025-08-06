#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();

    int originalColor = image[sr][sc];
    if(originalColor == color) return; 

    queue<pair<int, int>> q;
    q.push({sr, sc});

    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        image[x][y] = color;

        for(auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if(newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == originalColor) {
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    int m, n;
    cout << "Enter total number of rows and columns in image grid: ";
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));
    cout << "Enter image matrix:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> image[i][j];
        }
    }

    int sr, sc;
    cout << "Enter start position (sr, sc): ";
    cin >> sr >> sc;

    int color;
    cout << "Enter new color: ";
    cin >> color;

    floodFill(image, sr, sc, color);

    cout << "Updated image matrix:" << endl;
    for(auto row : image){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}