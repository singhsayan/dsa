#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void floydWarshall(int src, vector<vector<int>>&mat){
    int n = mat.size();
    for(int k = 0; k < n; k ++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][k] != ie8 && mat[k][j] != 1e8){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == ie8){
                mat[i][j] = -1;
            }
        }
    }
    cout << endl;
}

int main(){
    int rows, cols;
    cout << "Enter total number of rows and columns:" << endl;
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols, 1e8));


    cout << "enter weight of each cell:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];
    }

    int src;
    cout << "Enter the source node:" << endl;
    cin >> src;

    floydWarshall(src, mat);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " " << endl;
        }
    }
    return 0;
}