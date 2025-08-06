#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapsort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    int size = n;
    while(size > 1){
        swap(arr[0], arr[size - 1]);

        size --;

        heapify(arr, size, 0);
    }
    
}


int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    cout << "Sorted array in decreasing order: \n";
    for(int i = n - 1; i >= 0; i--){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}