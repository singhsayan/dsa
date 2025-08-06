#include <iostream>
using namespace std;

#define MAX 10 // Define maximum size for the matrix

int main() {
    int matrix[MAX][MAX];
    int rows, cols;

    // Input for the dimensions of the matrix
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Input for the matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Arrays to store the sums of each row and each column
    int rowSum[MAX] = {0};
    int colSum[MAX] = {0};

    // Calculate sums of each row and column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j]; // Sum for each row
            colSum[j] += matrix[i][j]; // Sum for each column
        }
    }

    // Display the sum of each row
    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": " << rowSum[i] << endl;
    }

    // Display the sum of each column
    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        cout << "Column " << j + 1 << ": " << colSum[j] << endl;
    }

    return 0;
}