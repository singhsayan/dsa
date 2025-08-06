#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafe(int row, int col, int num, vector<vector<int>>& graphs, int n, int boxSize) {
    for (int x = 0; x < n; x++) {
        if (graphs[row][x] == num || graphs[x][col] == num)
            return false;
    }

    int startRow = row - row % boxSize;
    int startCol = col - col % boxSize;

    for (int i = 0; i < boxSize; i++) {
        for (int j = 0; j < boxSize; j++) {
            if (graphs[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& graphs, int n, int boxSize) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (graphs[row][col] == 0) {
                for (int num = 1; num <= n; num++) {
                    if (isSafe(row, col, num, graphs, n, boxSize)) {
                        graphs[row][col] = num;

                        if (solveSudoku(graphs, n, boxSize))
                            return true;

                        graphs[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter size of matrix (e.g., 4 for 4x4): ";
    cin >> n;

    int boxSize = sqrt(n);
    if (boxSize * boxSize != n) {
        cout << "Invalid size! Sudoku must be n x n where √n is an integer." << endl;
        return 1;
    }

    vector<vector<int>> graphs(n, vector<int>(n));
    cout << "Enter the Sudoku (use 0 for blanks):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graphs[i][j];

    if (solveSudoku(graphs, n, boxSize)) {
        cout << "Solved Sudoku:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << graphs[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
