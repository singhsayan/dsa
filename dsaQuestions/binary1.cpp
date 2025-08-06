#include<iostream>
using namespace std;

bool binary(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int t;
    cout << "Enter the target element to search for: ";
    cin >> t;
    
    bool found = binary(arr, n, t);
    if (found) {
        cout << t << " exists in the given array" << endl;
    } else {
        cout << t << " does not exist in the given array" << endl;
    }
    return 0;
}