#include<iostream>
using namespace std;

void swap(int arr[], int size){
    for(int i = 0; i < size; i+=2){
        if(i + 1 < size){
            // swap(arr[i], arr[i + 1])
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}


void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int size;
    cout << "Enter size of an array" << endl;
    cin >> size;
    cout << endl;

    int arr1[size];
    cout << "Enter elements of array" << endl;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i + 1 << endl;
        cin >> arr1[i];
    }

    swap(arr1, size);
    cout << "Array after swapping alternate elements is" << endl;
    printArr(arr1, size);

    return 0;
    
}