#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int m;
    cout << "Enter size of array:" << endl;
    cin >> m;

    vector<int> arrival(m);
    vector<int> departure(m);

    cout << "Enter value in both arrays:" << endl;
    for(int i = 0; i < m; i++){
        cout << "Enter arrival time:" << endl;
        cin >> arrival[i];
        cout << "Enter departure time:" << endl;
        cin >> departure[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int maxPlatforms = 0;
    int platforms = 0;
    int i = 0;
    int j = 0;
    while(i < m && j < m){
        if(arrival[i] <= departure[j]){
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        else{
            platforms--;
            j++;
        }
    }

    cout << "Minimum platforms needed:" << endl;
    cout << maxPlatforms << endl;
    return 0;
}