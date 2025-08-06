#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices, int n){
    if(n == 0) return 0;

    int maxi = 0;
    int mini = prices[0];

    for(int i = 0; i < n; i++){
        int diff = prices[i] - mini;
        maxi = max(maxi, diff);
        mini = min(mini, prices[i]);
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int>prices(n);

    cout << "Enter prices of stock:" << endl;
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    cout << "Maximum profit achievable is:" << endl;
    cout << maxProfit(prices, n);
    return 0;
}