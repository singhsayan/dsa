#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maximumPoints(vector<vector<int>> &arr, int n, vector<vector<int>> &dp) {
    vector<int> prev(3, 0); // Store the previous day's points

    // Initialize base case for the first day
    prev[0] = arr[0][0];
    prev[1] = arr[0][1];
    prev[2] = arr[0][2];

    // Iterate through subsequent days
    for (int day = 1; day < n; day++) {
        vector<int> curr(3, 0); // Store current day's points

        // Calculate points for each activity on the current day
        curr[0] = arr[day][0] + max(prev[1], prev[2]);
        curr[1] = arr[day][1] + max(prev[0], prev[2]);
        curr[2] = arr[day][2] + max(prev[0], prev[1]);

        // Update the previous day's points for the next iteration
        prev = curr;
    }

    // Return the maximum points on the last day
    return max(prev[0], max(prev[1], prev[2]));
}

int main() {
    vector<vector<int>> arr = {{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    int n = arr.size();
    
    // Call the space optimized function
    cout << "Maximum Merit Points: " << maximumPoints(arr, n, dp) << endl;
    return 0;
}