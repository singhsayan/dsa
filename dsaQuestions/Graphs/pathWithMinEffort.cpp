#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    effort[0][0] = 0;

    priority_queue< pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>> > pq;

    pq.push({0, {0, 0}});

    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    while(!pq.empty()) {
        auto [currEffort, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;

        if(x == n-1 && y == m-1) return currEffort;

        for(auto [dx, dy] : directions) {
            int newX = x + dx, newY = y + dy;
            if(newX >= 0 && newY >= 0 && newX < n && newY < m) {
                int newEffort = max(currEffort, abs(heights[x][y] - heights[newX][newY]));
                if(newEffort < effort[newX][newY]) {
                    effort[newX][newY] = newEffort;
                    pq.push({newEffort, {newX, newY}});
                }
            }
        }
    }

    return 0;
}

int main(){
    int n, m; 
    cout << "Enter value of n and m:" << endl;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));

    cout << "Enter value of height of cells:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> heights[i][j];
        }
    }

    int minEffort = minimumEffortPath(heights);
    cout << "Minimum effort required is: " << minEffort << endl;

    return 0;
}