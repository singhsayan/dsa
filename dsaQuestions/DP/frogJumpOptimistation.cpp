#include<iostream>
using namespace std;


int miniEnergy(int n, vector<int> &height){
     // Variables to store the minimum energy for the last two steps
    int prev2 = 0; // Energy required to reach step 0
    int prev1 = 0; // Energy required to reach step 1

    for (int i = 1; i < n; i++) {
        // Energy to jump from i-1 to i
        int jump1 = prev1 + abs(height[i] - height[i - 1]);
        
        // Energy to jump from i-2 to i (if valid)
        int jump2 = (i > 1) ? prev2 + abs(height[i] - height[i - 2]) : INT_MAX;

        // Update current energy as the minimum of jump1 and jump2
        int curr = min(jump1, jump2);

        // Update prev2 and prev1 for the next iteration
        prev2 = prev1;
        prev1 = curr;
    }

    // The answer is stored in prev1 (energy to reach the last step)
    return prev1;
}

int main() {
    int n;
    cout << "Enter the number of steps:" << endl;
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of each step: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    // Call the function to calculate the minimum energy
    cout << "Minimum energy to reach the top: " << miniEnergy(height, n) << endl;

    return 0;
}