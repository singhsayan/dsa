#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool isSafe(int vertex, int color, vector<int>&colors, vector<vector<int>>&arr, int n){
    for(int i = 0; i < n; i++){
        if(arr[vertex][i] == 1 && colors[i] == color){
            return false;
        }
    }
    return true;
}

bool mColoring(int vertex, int m, vector<int>&colors, vector<vector<int>>&arr, int n){
    if(vertex == n){
        cout << "Assigned colors are:" << endl;
        for(int i = 0; i < n; i++){
            cout << colors[i] << " " << endl;
        }
        return true;
    }

    for(int colorsToTry = 1; colorsToTry <= m; colorsToTry++){
        if(isSafe(vertex, colorsToTry, colors, arr, n)){
            colors[vertex] = colorsToTry;
            if(mColoring(vertex + 1, m, colors, arr, n)){
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main(){
    int n, m;
    cout << "Enter size of matrix:" << endl;
    cin >> n >> m;


    vector<vector<int>>arr(n, vector<int>(n));

    cout << "Enter values in undirected graph:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int>colors(n, 0);

    int found = false;

    for(int m = 0; m <= n; m++){
        fill(colors.begin(), colors.end(), 0);

        if(mColoring(0, m, colors, arr, n)){
            cout << "Minimum colors needed are:" << m << endl;
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Solution doesn't exist:" << endl;
    }

    return 0;
}