#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Custom comparator function (replacing lambda)
bool comparePairs(const pair<double, int>& a, const pair<double, int>& b) {
    return a.first > b.first; // Sort in descending order
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<pair<double, int> > ratioIndex; // Fix spacing: '>>' -> '> >'

    // Store value-to-weight ratio with index
    for (int i = 0; i < n; i++) {
        ratioIndex.push_back(make_pair((double)val[i] / wt[i], i)); // Use make_pair instead of {}
    }

    // Sorting in descending order
    sort(ratioIndex.begin(), ratioIndex.end(), comparePairs);

    double maxValue = 0.0;

    for (int i = 0; i < n; i++) {
        int index = ratioIndex[i].second;
        if (wt[index] <= capacity) {
            maxValue += val[index];
            capacity -= wt[index];
        } else {
            maxValue += (double)val[index] * capacity / wt[index];
            break;
        }
    }

    return maxValue;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter number of items: ";
        cin >> n;

        vector<int> values(n), weights(n);
        cout << "Enter values of items: ";
        for (int i = 0; i < n; i++) cin >> values[i];

        cout << "Enter weights of items: ";
        for (int i = 0; i < n; i++) cin >> weights[i];

        int capacity;
        cout << "Enter knapsack capacity: ";
        cin >> capacity;

        cout << fixed << setprecision(6); // Set output precision to 6 decimal places
        cout << "Maximum value in Knapsack = " << fractionalKnapsack(values, weights, capacity) << endl;
    }
    return 0;
}