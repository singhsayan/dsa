#include <iostream>
using namespace std;

void input(int trip[][3], int &nz) {
    cin >> trip[0][0] >> trip[0][1] >> nz;  // Input rows, cols, and non-zero elements
    for (int i = 1; i <= nz; i++)
        cin >> trip[i][0] >> trip[i][1] >> trip[i][2];  // Input triplet elements
}

void multiply(int A[][3], int B[][3], int res[][3], int nzA, int nzB) {
    int k = 1;
    res[0][0] = A[0][0]; res[0][1] = B[0][1]; res[0][2] = 0;

    for (int i = 1; i <= nzA; i++) {
        for (int j = 1; j <= nzB; j++) {
            if (A[i][1] == B[j][0]) {
                res[k][0] = A[i][0];
                res[k][1] = B[j][1];
                res[k][2] = A[i][2] * B[j][2];
                res[0][2]++; k++;
            }
        }
    }
}

void print(int trip[][3], int nz) {
    for (int i = 0; i <= nz; i++)
        cout << trip[i][0] << "\t" << trip[i][1] << "\t" << trip[i][2] << "\n";
}

int main() {
    int A[100][3], B[100][3], res[100][3], nzA, nzB;

    input(A, nzA);
    input(B, nzB);
    
    if (A[0][1] != B[0][0]) {
        cout << "Incompatible for multiplication\n";
        return 0;
    }

    multiply(A, B, res, nzA, nzB);
    print(res, res[0][2]);

    return 0;
}