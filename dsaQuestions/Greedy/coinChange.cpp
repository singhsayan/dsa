#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    int amt;
    cout << "Enter amount" << endl;
    cin >> amt;

    vector<int>coins(n);

    cout << "Enter values present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end(), greater<int>());

    int minCoins = 0;
    int i = 0;

    while(i < n){
        if(amt >= coins[i]){
            int count = amt / coins[i];
            minCoins += count;
            amt -= coins[i] * count;
        }
        i++;
    }

    if (amt == 0)
        cout << "Minimum number of coins needed: " << minCoins << endl;
    else
        cout << "Cannot make the amount with given coins." << endl;

    return 0;

}