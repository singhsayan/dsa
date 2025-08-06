#include<iostream>
#include<vector> 
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}

int main(){
    int size;
    cout << "Enter size of an array: ";
    cin >> size;
    cout << endl;

    vector<int> arr1(size); 
    cout << "Enter elements of array:" << endl;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr1[i];
    }

    cout << "Unique element present in the array is: " << findDuplicate(arr1) << endl;

    return 0;
}