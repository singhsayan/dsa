#include<iostream>
#include<vector>
using namespace std;

int knapsack(int i, int n, vector<int>& weights, vector<int>& profits, int w) {
    if(i == n || w == 0) return 0;

    if(weights[i] <= w) {
        int include = profits[i] + knapsack(i + 1, n, weights, profits, w - weights[i]);
        int exclude = knapsack(i + 1, n, weights, profits, w);
        return max(include, exclude);
    } 
    else {
        return knapsack(i + 1, n, weights, profits, w);
    }
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), profits(n);
    
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter profits: ";
    for(int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    int w;
    cout << "Enter capacity of the bag: ";
    cin >> w;

    int maxProfit = knapsack(0, n, weights, profits, w);
    cout << "Maximum profit possible: " << maxProfit << endl;

    return 0;
}