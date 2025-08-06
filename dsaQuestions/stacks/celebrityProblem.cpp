#include <iostream>
#include <stack>
using namespace std;

bool knows(int mat[][100], int a, int b, int n) {
    return mat[a][b] == 1;
}

int findCelebrity(int mat[][100], int n) {
    stack<int> s;

    // Step 1: Push all candidates into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        if (knows(mat, a, b, n)) {
            s.push(b);
        }
         else {
            s.push(a);
        }
    }

    // Step 3: Single element in stack is a potential celebrity
    int candidate = s.top();

    // Row check: The candidate should not know anyone
    bool rowCheck = true;
    for (int i = 0; i < n; i++) {
        if (mat[candidate][i] == 1) {
            rowCheck = false;
            break;
        }
    }

    // Column check: Everyone should know the candidate
    bool colCheck = true;
    for (int i = 0; i < n; i++) {
        if (i != candidate && mat[i][candidate] == 0) {
            colCheck = false;
            break;
        }
    }

    // If both row and column checks pass, return the candidate, otherwise return -1
    if (rowCheck && colCheck) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cout << "Enter the number of people (n): ";
    cin >> n;

    int mat[100][100];
    cout << "Enter the " << n << "x" << n << " matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int result = findCelebrity(mat, n);
    if (result == -1) {
        cout << "No celebrity found.\n";
    } else {
        cout << "The celebrity is person " << result << ".\n";
    }

    return 0;
}