#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void candidates(int i, vector<int>&arr, int target, vector<int>&temp, vector<vector<int>>&result){
    if(target == 0){
        result.push_back(temp);
        return;
    }
    if (i == arr.size()) return;

    if(target >= arr[i]){
        temp.push_back(arr[i]);
        candidates(i, arr, target - arr[i], temp, result);
        temp.pop_back();
    }

    candidates(i + 1, arr, target, temp, result);

}


int main(){

    int n;
    cout << "Enter size of stack:" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of sum you want to check:" << endl;
    cin >> k;    

    vector<vector<int>> result;
    vector<int> temp;

     candidates(0, arr, k, temp, result);

    cout << "Possible combinations with given sum:" << endl;
    if (result.empty()) {
        cout << "No combinations found." << endl;
    } else {
        for (const auto& vec : result) {
            for (int num : vec) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}