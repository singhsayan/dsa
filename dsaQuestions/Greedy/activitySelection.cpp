#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool activityCompare(pair<int,int>&a, pair<int,int>&b){
    return a.first < b.second;
}

int main(){
    int m;
    cout << "Enter number of activities:" << endl;
    cin >> m;

    vector<int> start(m);
    vector<int> end(m);

    cout << "Enter start times:" << endl;
    for(int i = 0; i < m; i++){
        cin >> start[i];
    }

    cout << "Enter end times:" << endl;
    for(int i = 0; i < m; i++){
        cin >> end[i];
    }

    vector<pair<int,int>> activites;
    for(int i = 0; i < m; i++){
        activites.push_back({end[i], start[i]});
    }

    sort(activites.begin(), activites.end(), activityCompare);

    int count = 1;
    int lastEnd = activites[0].first;

    for(int i = 0; i < m; i++){
        if(activites[i].second >= lastEnd){
            count++;
            cout << activites[i].second << "," << activites[i].first << endl;
            lastEnd = activites[i].first;
        }
    }

    cout << "Maximum number of activites possible:" << endl;
    cout << count << endl;

    return 0;
}