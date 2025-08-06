#include<iostream>
using namespace std;

int findUnique(int arr1[], int size){
    int uniqueEle = 0;

    for(int i = 0; i < size; i++){
        uniqueEle = uniqueEle ^ arr1[i];  
    }

    return uniqueEle;
}

int main(){
    int size;
    cout << "Enter size of an array: ";
    cin >> size;
    cout << endl;

    int *arr1 = new int[size]; 
    cout << "Enter elements of array:" << endl;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr1[i];
    }

    cout << "Unique element present in the array is: " << findUnique(arr1, size) << endl;

    delete[] arr1;  
    return 0;
}