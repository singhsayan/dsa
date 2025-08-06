#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> prev(n, 1); // Initialize the first row

    for (int i = 1; i < m; i++) {
        vector<int> curr(n, 1); // Current row
        for (int j = 1; j < n; j++) {
            //prev[j] represents the number of ways to reach that cell from above (i.e., moving down).
            //curr[j-1] represents the number of ways to reach that cell from the left (i.e., moving right).
            curr[j] = prev[j] + curr[j - 1];
        }
        //After processing the current row, we update the prev vector to be the curr vector.
        // This is because the next row will need the values from the current row (now stored in prev).
        prev = curr; // Update previous row
    }

    return prev[n - 1];
}

int main() {
    int m = 3, n = 7;
    cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}