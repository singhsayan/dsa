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

    for(int i = 1; i < n; i++){
        bool swapped = false;
        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }


    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}