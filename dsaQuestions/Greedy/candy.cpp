#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter ratings value:" << endl;
    for(int i = 0; i < n; i++){
        cin >> ratings[i];
    }

    vector<int> candies(n, 1);

    for(int i = 1; i < n; i++){
        if(ratings[i] > ratings[i - 1]){
            candies[i] = candies[i - 1] + 1;
        }
    }

    for(int i = n - 2; i >= 0; i--){
        if(ratings[i] > ratings[i + 1]){
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int totalCandies = 0;
    for(int c : candies) totalCandies += c;
    
    cout << "Minimum number of candies needed to distribute among children:" << endl;
    cout << totalCandies << endl;

    return 0;

}