#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int>arr(n);

    cout << "Enter values present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count = 1;
    int majorityEle = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] == majorityEle){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            majorityEle = arr[i];
            count = 1;
        }
    }

    int actualCount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == majorityEle){
            actualCount++;
        }
    }

    if(actualCount > n /2){
        cout << "Majority element is:" << majorityEle << endl;
    }
    else{
        cout << "majority element doesn't exist" << endl;
    }

    return 0;
}
