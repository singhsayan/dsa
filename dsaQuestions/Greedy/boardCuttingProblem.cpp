#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int boardCutting(vector<int>& cost_x, vector<int>& cost_y) {
    sort(cost_x.rbegin(), cost_x.rend());
    sort(cost_y.rbegin(), cost_y.rend());

    int i = 0, j = 0;
    int row_pieces = 1, col_pieces = 1;
    long long total_cost = 0;

    while (i < cost_y.size() && j < cost_x.size()) {
        if (cost_y[i] >= cost_x[j]) {
            total_cost = (total_cost + 1LL * cost_y[i] * col_pieces) % MOD;
            row_pieces++;
            i++;
        } else {
            total_cost = (total_cost + 1LL * cost_x[j] * row_pieces) % MOD;
            col_pieces++;
            j++;
        }
    }

    // Remaining horizontal cuts
    while (i < cost_y.size()) {
        total_cost = (total_cost + 1LL * cost_y[i] * col_pieces) % MOD;
        i++;
    }

    // Remaining vertical cuts
    while (j < cost_x.size()) {
        total_cost = (total_cost + 1LL * cost_x[j] * row_pieces) % MOD;
        j++;
    }

    return total_cost;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int m, n;
        cin >> m >> n;

        vector<int> cost_y(m - 1);
        vector<int> cost_x(n - 1);

        for (int i = 0; i < m - 1; i++)
            cin >> cost_y[i];

        for (int j = 0; j < n - 1; j++)
            cin >> cost_x[j];

        cout << boardCutting(cost_x, cost_y) << endl;
    }

    return 0;
}
