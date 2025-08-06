#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void merge(int s, int e, vector<int>&arr){
    int mid = (s + e) / 2;

    int i = s;
    int j = mid + 1;

    vector<int>temp;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++){
        arr[s + k] = temp[k];
    }
}

void mergeSort(int i, int j, vector<int>&arr){
    if(i >= j) return;

    int mid = (i + j)/2;
    
    mergeSort(i, mid, arr);
    mergeSort(mid + 1, j, arr);

    merge(i, j, arr);
}


int main(){
   int n;
   cout << "Enter size of array:" << endl;
   cin >> n;

   vector<int>arr(n);

   cout << "Enter values in array:" << endl;
   for(int i = 0; i < n; i++){
    cin >> arr[i];
   }

   mergeSort(0, n - 1, arr);

   cout << "Sorted array is:" << endl;
   for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
        cout << endl;
   }

    return 0;
}