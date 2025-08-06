#include<iostream>
#include<vector>
using namespace std;

// Partition function returns pivot index after placing it at correct position
int partition(int s, int e, vector<int>& arr) {
    int pivot = arr[s];
    int i = s;

    for(int j = s + 1; j <= e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[i]);
    return i;  // Pivot index
}

// Recursive quicksort
void quickSort(int low, int high, vector<int>& arr) {
    if(low < high) {
        int pi = partition(low, high, arr);
        quickSort(low, pi - 1, arr);
        quickSort(pi + 1, high, arr);
    }
}

int main() {
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values in array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(0, n - 1, arr);

    cout << "Sorted array is:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
