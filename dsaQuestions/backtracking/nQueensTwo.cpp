#include <iostream>
#include <vector>
#include<string>
using namespace std;

void Nqueens(int row, vector<bool>&columns,vector<bool>&diagonal1, vector<bool>&diagonal2,
    vector<int>&current, vector<vector<int>>&results,int nQueens){
        if(row == nQueens){
            results.push_back(current);
            return;
        }

        for(int col = 0; col < nQueens; col++){
            int d1 = row + col;
            int d2 = row - col + nQueens - 1;

            if(diagonal1[d1] || diagonal2[d2] || columns[col]){
                continue;
            }
            diagonal1[d1] = diagonal2[d2] = columns[col] = true;
            current.push_back(col + 1);

            Nqueens(row + 1, columns, diagonal1, diagonal2, current, results, nQueens);

            columns[col] = diagonal1[d1] = diagonal2[d2] = false;
            current.pop_back();
        }
    }

int main() {
    int nQueens;
    cout << "Enter total number of queens (n): ";
    cin >> nQueens;

    vector<bool> columns(nQueens, false);
    vector<bool> diagonal1(2 * nQueens - 1, false);
    vector<bool> diagonal2(2 * nQueens - 1, false);
    vector<int> current;
    vector<vector<int>> results;

    Nqueens(0, columns, diagonal1, diagonal2, current, results, nQueens);

    cout << "All valid solutions:" << endl;
    for(auto &solution: results){
        cout << "[";
        for(int i = 0; i < solution.size(); i++){
            cout << solution[i];
            if (i != solution.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}