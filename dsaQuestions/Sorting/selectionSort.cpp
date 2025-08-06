#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter total number of elements present in an array:" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter elements to add in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}