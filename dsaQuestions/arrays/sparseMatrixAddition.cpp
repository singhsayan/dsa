#include <iostream>
using namespace std;

void inputSparseMatrix(int sparse[][3], int &rows, int &cols, int &nonZero) {
    cout << "Enter rows, columns, and number of non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    cout << "Enter triplet representation (row column value):\n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }
}

void printSparseMatrix(int sparse[][3]) {
    cout << "Triplet representation:\n";
    for (int i = 0; i <= sparse[0][2]; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }
}

void addSparseMatrices(int s1[][3], int s2[][3], int res[][3]) {
    int nz1 = s1[0][2], nz2 = s2[0][2], i = 1, j = 1, k = 1;
    res[0][0] = s1[0][0]; res[0][1] = s1[0][1]; res[0][2] = 0;

    while (i <= nz1 && j <= nz2) {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1]) {
            res[k][0] = s1[i][0]; res[k][1] = s1[i][1]; res[k][2] = s1[i][2] + s2[j][2];
            i++; j++;
        } else if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            res[k][0] = s1[i][0]; res[k][1] = s1[i][1]; res[k][2] = s1[i][2];
            i++;
        } else {
            res[k][0] = s2[j][0]; res[k][1] = s2[j][1]; res[k][2] = s2[j][2];
            j++;
        }
        k++;
    }

    while (i <= nz1) { res[k][0] = s1[i][0]; res[k][1] = s1[i][1]; res[k][2] = s1[i][2]; i++; k++; }
    while (j <= nz2) { res[k][0] = s2[j][0]; res[k][1] = s2[j][1]; res[k][2] = s2[j][2]; j++; k++; }

    res[0][2] = k - 1;
}

int main() {
    int sparse1[100][3], sparse2[100][3], result[100][3];
    int rows1, cols1, nonZero1, rows2, cols2, nonZero2;

    cout << "Input first sparse matrix:\n";
    inputSparseMatrix(sparse1, rows1, cols1, nonZero1);

    cout << "\nInput second sparse matrix:\n";
    inputSparseMatrix(sparse2, rows2, cols2, nonZero2);

    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Sparse matrices must have the same dimensions for addition.\n";
        return 1;
    }

    addSparseMatrices(sparse1, sparse2, result);

    cout << "\nResultant sparse matrix:\n";
    printSparseMatrix(result);

    return 0;
}