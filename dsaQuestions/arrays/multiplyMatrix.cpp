#include <iostream>

using namespace std;

#define MAX 100 // Define a maximum size for the matrices

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    // Initialize result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply the matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
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
    int first[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int second[MAX][MAX] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int result[MAX][MAX]; // To store the result of the multiplication
    int r1 = 2; // Number of rows in first matrix
    int c1 = 3; // Number of columns in first matrix
    int r2 = 3; // Number of rows in second matrix
    int c2 = 2; // Number of columns in second matrix

    // Check if multiplication is possible (columns of first = rows of second)
    if (c1 != r2) {
        cout << "Matrix multiplication not possible." << endl;
        return 0;
    }

    // Multiply the matrices
    multiplyMatrices(first, second, result, r1, c1, r2, c2);

    cout << "Resulting Matrix after multiplication:" << endl;
    displayMatrix(result, r1, c2); // Display the result matrix

    return 0;
}