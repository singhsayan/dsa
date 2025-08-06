#include <iostream>
using namespace std;

// Node for linked list representation of sparse matrix
class Node {
public:
    int row, col, value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Class for sparse matrix linked list
class SparseMatrixLinkedList {
    Node* head;

public:
    SparseMatrixLinkedList() : head(nullptr) {}

    // Function to insert a new non-zero element
    void insert(int row, int col, int value) {
        Node* newNode = new Node(row, col, value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the sparse matrix
    void display() {
        Node* temp = head;
        cout << "Row\tCol\tValue\n";
        while (temp) {
            cout << temp->row << "\t" << temp->col << "\t" << temp->value << endl;
            temp = temp->next;
        }
    }

    // Sparse matrix addition (linked list-based)
    static SparseMatrixLinkedList* add(SparseMatrixLinkedList* A, SparseMatrixLinkedList* B) {
        SparseMatrixLinkedList* C = new SparseMatrixLinkedList();
        Node* pA = A->head;
        Node* pB = B->head;

        while (pA && pB) {
            if (pA->row < pB->row || (pA->row == pB->row && pA->col < pB->col)) {
                C->insert(pA->row, pA->col, pA->value);
                pA = pA->next;
            } else if (pA->row > pB->row || (pA->row == pB->row && pA->col > pB->col)) {
                C->insert(pB->row, pB->col, pB->value);
                pB = pB->next;
            } else {
                int newValue = pA->value + pB->value;
                if (newValue != 0) {
                    C->insert(pA->row, pA->col, newValue);
                }
                pA = pA->next;
                pB = pB->next;
            }
        }

        while (pA) {
            C->insert(pA->row, pA->col, pA->value);
            pA = pA->next;
        }
        while (pB) {
            C->insert(pB->row, pB->col, pB->value);
            pB = pB->next;
        }

        return C;
    }

    // Sparse matrix subtraction (linked list-based)
    static SparseMatrixLinkedList* subtract(SparseMatrixLinkedList* A, SparseMatrixLinkedList* B) {
        SparseMatrixLinkedList* C = new SparseMatrixLinkedList();
        Node* pA = A->head;
        Node* pB = B->head;

        while (pA && pB) {
            if (pA->row < pB->row || (pA->row == pB->row && pA->col < pB->col)) {
                C->insert(pA->row, pA->col, pA->value);
                pA = pA->next;
            } else if (pA->row > pB->row || (pA->row == pB->row && pA->col > pB->col)) {
                C->insert(pB->row, pB->col, -pB->value);
                pB = pB->next;
            } else {
                int newValue = pA->value - pB->value;
                if (newValue != 0) {
                    C->insert(pA->row, pA->col, newValue);
                }
                pA = pA->next;
                pB = pB->next;
            }
        }

        while (pA) {
            C->insert(pA->row, pA->col, pA->value);
            pA = pA->next;
        }
        while (pB) {
            C->insert(pB->row, pB->col, -pB->value);
            pB = pB->next;
        }

        return C;
    }

    // Sparse matrix transpose (linked list-based)
    static SparseMatrixLinkedList* transpose(SparseMatrixLinkedList* A) {
        SparseMatrixLinkedList* T = new SparseMatrixLinkedList();
        Node* temp = A->head;

        while (temp) {
            T->insert(temp->col, temp->row, temp->value);
            temp = temp->next;
        }

        return T;
    }
};

int main() {
    SparseMatrixLinkedList* A = new SparseMatrixLinkedList();
    A->insert(0, 1, 5);
    A->insert(1, 2, 8);
    A->insert(2, 0, 3);

    SparseMatrixLinkedList* B = new SparseMatrixLinkedList();
    B->insert(0, 1, 2);
    B->insert(1, 0, 6);
    B->insert(2, 0, 7);

    cout << "\nMatrix A:\n";
    A->display();

    cout << "\nMatrix B:\n";
    B->display();

    // Addition
    SparseMatrixLinkedList* C = SparseMatrixLinkedList::add(A, B);
    cout << "\nAddition Result:\n";
    C->display();

    // Subtraction
    SparseMatrixLinkedList* D = SparseMatrixLinkedList::subtract(A, B);
    cout << "\nSubtraction Result:\n";
    D->display();

    // Transpose of A
    SparseMatrixLinkedList* T = SparseMatrixLinkedList::transpose(A);
    cout << "\nTranspose of Matrix A:\n";
    T->display();

    // Cleanup
    delete A;
    delete B;
    delete C;
    delete D;
    delete T;

    return 0;
}