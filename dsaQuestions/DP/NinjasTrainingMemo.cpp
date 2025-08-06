#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumPoints(vector<vector<int> > &arr, int n, vector<vector<int> > &dp){
    // base case for the first day
    // n represents no of days
    int maxPoints;
    if(n == 0){
        maxPoints = 0;
        for(int activity = 0; activity < 3; activity++){
            maxPoints = max(maxPoints, arr[0][activity]);
        }
    }
    return maxPoints;

    if(dp[n][3] != -1) return dp[n][3];

    maxPoints = 0;

    // loop through the activities of the current day
    for(int activity = 0; activity < 3; activity++){
        // we need to ensure that we don't pick the same activity on the same conescutive days
        if(activity != 3){
            // n -1 is done for calculating for remaining (n - 1) days maximum points geek can earn
            int points = arr[n][activity] + maximumPoints(arr, n - 1, dp);
            maxPoints = max(points, maxPoints);
        }
    }

    return dp[n][3] = maxPoints;
}

int main() {
    // Initialize the 2D array explicitly
    vector<vector<int> > arr = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(4, -1));

    // Call the recursive function
    cout << "Maximum Merit Points: " << maximumPoints(arr, n - 1, dp) << endl;
    return 0;
}