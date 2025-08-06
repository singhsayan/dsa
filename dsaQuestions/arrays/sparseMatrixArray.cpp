#include <iostream>
using namespace std;

class SparseMatrixArray {
    int row, col, value;

public:
    SparseMatrixArray() : row(0), col(0), value(0) {}

    SparseMatrixArray(int r, int c, int v) : row(r), col(c), value(v) {}

    int getRow() const { return row; }
    int getCol() const { return col; }
    int getValue() const { return value; }

    // Function to display sparse matrix
    void display() const {
        cout << row << "\t" << col << "\t" << value << endl;
    }

    // Sparse matrix addition (array-based)
    static SparseMatrixArray* add(const SparseMatrixArray A[], const SparseMatrixArray B[], int sizeA, int sizeB, int &sizeC) {
        SparseMatrixArray* C = new SparseMatrixArray[sizeA + sizeB];
        int i = 0, j = 0, k = 0;

        while (i < sizeA && j < sizeB) {
            if (A[i].getRow() < B[j].getRow() || (A[i].getRow() == B[j].getRow() && A[i].getCol() < B[j].getCol())) {
                C[k++] = A[i++];
            } else if (A[i].getRow() > B[j].getRow() || (A[i].getRow() == B[j].getRow() && A[i].getCol() > B[j].getCol())) {
                C[k++] = B[j++];
            } else {
                int newValue = A[i].getValue() + B[j].getValue();
                if (newValue != 0) {
                    C[k++] = SparseMatrixArray(A[i].getRow(), A[i].getCol(), newValue);
                }
                i++;
                j++;
            }
        }

        while (i < sizeA) C[k++] = A[i++];
        while (j < sizeB) C[k++] = B[j++];

        sizeC = k;
        return C;
    }

    // Sparse matrix subtraction (array-based)
    static SparseMatrixArray* subtract(const SparseMatrixArray A[], const SparseMatrixArray B[], int sizeA, int sizeB, int &sizeC) {
        SparseMatrixArray* C = new SparseMatrixArray[sizeA + sizeB];
        int i = 0, j = 0, k = 0;

        while (i < sizeA && j < sizeB) {
            if (A[i].getRow() < B[j].getRow() || (A[i].getRow() == B[j].getRow() && A[i].getCol() < B[j].getCol())) {
                C[k++] = A[i++];
            } else if (A[i].getRow() > B[j].getRow() || (A[i].getRow() == B[j].getRow() && A[i].getCol() > B[j].getCol())) {
                C[k++] = SparseMatrixArray(B[j].getRow(), B[j].getCol(), -B[j].getValue());
                j++;
            } else {
                int newValue = A[i].getValue() - B[j].getValue();
                if (newValue != 0) {
                    C[k++] = SparseMatrixArray(A[i].getRow(), A[i].getCol(), newValue);
                }
                i++;
                j++;
            }
        }

        while (i < sizeA) C[k++] = A[i++];
        while (j < sizeB) C[k++] = SparseMatrixArray(B[j].getRow(), B[j].getCol(), -B[j++].getValue());

        sizeC = k;
        return C;
    }

    // Sparse matrix transpose (array-based)
    static SparseMatrixArray* transpose(const SparseMatrixArray A[], int sizeA, int &sizeT) {
        SparseMatrixArray* T = new SparseMatrixArray[sizeA];
        int k = 0;

        for (int i = 0; i < sizeA; i++) {
            T[k++] = SparseMatrixArray(A[i].getCol(), A[i].getRow(), A[i].getValue());
        }

        sizeT = k;
        return T;
    }
};

// Function to display a sparse matrix array
void displaySparseMatrixArray(SparseMatrixArray sparse[], int size) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < size; i++) {
        sparse[i].display();
    }
}

int main() {
    // Sparse matrix A
    SparseMatrixArray A[] = {
        SparseMatrixArray(0, 1, 5),
        SparseMatrixArray(1, 2, 8),
        SparseMatrixArray(2, 0, 3)
    };
    int sizeA = 3;

    // Sparse matrix B
    SparseMatrixArray B[] = {
        SparseMatrixArray(0, 1, 2),
        SparseMatrixArray(1, 0, 6),
        SparseMatrixArray(2, 0, 7)
    };
    int sizeB = 3;

    // Addition
    int sizeC = 0;
    SparseMatrixArray* C = SparseMatrixArray::add(A, B, sizeA, sizeB, sizeC);
    cout << "\nAddition Result:\n";
    displaySparseMatrixArray(C, sizeC);

    // Subtraction
    int sizeD = 0;
    SparseMatrixArray* D = SparseMatrixArray::subtract(A, B, sizeA, sizeB, sizeD);
    cout << "\nSubtraction Result:\n";
    displaySparseMatrixArray(D, sizeD);

    // Transpose of A
    int sizeT = 0;
    SparseMatrixArray* T = SparseMatrixArray::transpose(A, sizeA, sizeT);
    cout << "\nTranspose of Matrix A:\n";
    displaySparseMatrixArray(T, sizeT);

    // Cleanup
    delete[] C;
    delete[] D;
    delete[] T;

    return 0;
}