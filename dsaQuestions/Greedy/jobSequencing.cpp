#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int>&a, pair<int,int>&b){
    return a.first > b.first;
}

int main(){
    int m;
    cout << "Enter size of array:" << endl;
    cin >> m;

    vector<int> deadline(m);
    vector<int> profit(m);

    cout << "Enter value of deadlines:" << endl;
    for(int i = 0; i < m; i++){
        cin >> deadline[i];
    }

    cout << "Enter value of profits:" << endl;
    for(int i = 0; i < m; i++){
        cin >> profit[i];
    }

    vector<pair<int,int>> jobId;
    for(int i = 0; i < m; i++){
        jobId.push_back({profit[i], deadline[i]});
    }

    sort(jobId.begin(), jobId.end(), compare);

    int maxDeadline = 0;
    for(int i = 0; i < m; i++){
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    vector<int> slot(maxDeadline + 1, -1);
    int maxProfit = 0;
    int jobsDone = 0;

    for(int i = 0; i < m; i++){
        int jobProfit = profit[i];
        int jobDeadline = deadline[i];

        for(int j = jobDeadline; j >= 0; j--){
            if(slot[j] == -1){
                slot[i] = j;
                maxProfit += jobProfit;
                jobsDone++;
                break;
            }
        }
    }

    cout << "Maximum profit:" << maxProfit << endl;
    cout << "Total jobs done:" << jobsDone << endl;
    
    return 0;
}