#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool isSafe(int vertex, int colorToTry, vector<int>&colors, vector<vector<int>>&graphs, int n){
    for(int i = 0; i <n; i++){
        if(graphs[vertex][i] == 1 && colors[i] == colorToTry){
            return false;
        }
    }
    return true;
}

bool mColoring(int vertex, int m, vector<int>&colors, vector<vector<int>>&graphs, int n){
    if(vertex == n){
        for(auto c: colors){
        cout << c << " ";
        }
        cout << endl;
        return true;
    }

    for(int colorToTry = 1; colorToTry <= m; colorToTry++){
        if(isSafe(vertex, colorToTry, colors, graphs, n)){
            colors[vertex] = colorToTry;
            if(mColoring(vertex + 1, m, colors, graphs, n)){
                return true;
            }
            colors[vertex] = 0;
        }
    }

    return false;
}

int main(){
    int n;
    cout << "enter size of matrix:" << endl;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjaceny matrix:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    vector<int> colors(n, 0);

    bool found = false;

    for (int m = 1; m <= n; m++) {
        fill(colors.begin(), colors.end(), 0);  

        if (mColoring(0, m, colors, graph, n)) {
            cout << "Minimum colors needed: " << m << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}