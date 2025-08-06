#include <iostream>

using namespace std;

#define MAX 100 // Define a maximum size for the matrix

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    // Fill the transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; // Assign element at (i, j) to (j, i)
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }
}

int main() {
    int matrix[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int transposed[MAX][MAX]; // To store the transposed matrix
    int rows = 3; // Number of rows
    int cols = 3; // Number of columns

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix, rows, cols); // Display original matrix

    // Find the transpose
    transposeMatrix(matrix, transposed, rows, cols);

    cout << "Transposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows); // Display transposed matrix

    return 0;
}