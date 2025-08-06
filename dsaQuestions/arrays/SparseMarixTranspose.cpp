#include <iostream>
using namespace std;

int main() {
    int sparse[5][5], m, n, ctr = 0;

    // Input dimensions and matrix
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> sparse[i][j];

    // Count non-zero elements
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (sparse[i][j] != 0) ctr++;

    // Create triplet representation
    int trip[ctr + 1][3], k = 1;
    trip[0][0] = m; trip[0][1] = n; trip[0][2] = ctr;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (sparse[i][j] != 0) {
                trip[k][0] = i; trip[k][1] = j; trip[k++][2] = sparse[i][j];
            }

    // Display triplet
    cout << "Triplet representation:\n";
    for (int i = 0; i <= ctr; i++)
        cout << trip[i][0] << "\t" << trip[i][1] << "\t" << trip[i][2] << "\n";

    // Transpose
    int trans[ctr + 1][3];
    trans[0][0] = n; trans[0][1] = m; trans[0][2] = ctr; k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= ctr; j++)
            if (trip[j][1] == i) {
                trans[k][0] = trip[j][1]; trans[k][1] = trip[j][0]; trans[k++][2] = trip[j][2];
            }

    // Display transpose
    cout << "Transpose of triplet:\n";
    for (int i = 0; i <= ctr; i++)
        cout << trans[i][0] << "\t" << trans[i][1] << "\t" << trans[i][2] << "\n";

    return 0;
}