#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

bool isSafe(int i, int j, int num, vector<vector<int>>&mat, int n){
    for(int x = 0; x < n; i++){
        if(mat[i][x] == num || mat[x][j] == num){
            return false;
        }
    }
    int startRow = i - i % 3;


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i + startRow][j + startCol] == num){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>&mat, int n){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 9; j++){
            if(mat[i][j] == 0){
                for(int num = 1; num <= 9; num++){
                    if(isSafe(i, j, num, mat, n)){
                        mat[i][j] = num;

                        if(solveSudoku(mat, n)){
                            return true;
                        }

                        mat[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}

int main(){
   int n;
   cout << "Enter size of array:" << endl;
   cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

   if(solveSudoku(mat, n)){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << mat[i][j] << " " << endl;
        }
    }
   }
   
   return 0;
}