#include<iostream>
#include<string>
#include<vector>
using namespace std;


void Nqueens(int row, vector<bool>&columns, vector<bool>&diagonal1, vector<bool>&diagonal2, vector<vector<string>>&results,
    vector<string>&board, int nQueens){
        if(row == nQueens){
            results.push_back(board);
            return;
        }

        for(int col = 0; col < nQueens; col++){
            int d1 = row + col;
            int d2 = row - col + nQueens - 1;

            if(diagonal1[d1] || diagonal2[d2] || columns[col]){
                continue;
            }

            board[row][col] = 'Q';
            columns[col] = diagonal1[d1] = diagonal2[d2] = true;

            Nqueens(row + 1, columns, diagonal1, diagonal2, results, board, nQueens);

            board[row][col] = '.';
            columns[col] = diagonal1[d1] = diagonal2[d2] = false;
        }
    }

int main(){
    int nQueens;
    cout << "Enter total no of queens present:" << endl;
    cin >> nQueens;

    vector<string> board(nQueens, string(nQueens, '.'));
    vector<bool> columns(nQueens, false);
    vector<bool> diagonal1(2 * nQueens - 1, false);
    vector<bool> diagonal2(2 * nQueens - 1, false);
    vector<vector<string>> results;

    Nqueens(0, columns, diagonal1, diagonal2, results, board, nQueens);

    for(auto num: results){
        for(auto ele: num){
            cout << ele << " " << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}