#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

class Stack {
public:
    int top;
    int size;
    int *arr;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top < size - 1) {
            top++;
            arr[top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            int ele = arr[top];
            top--;
            return ele;
        }
        return -1;
    }

    int peek() {
        if (top >= 0)
            return arr[top];
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void nextSmallerEle(int arr1[], int arr2[], int nums1Size, int nums2Size) {
        unordered_map<int, int> nextSmaller;
        Stack st(nums2Size);

        // Calculate next smaller elements for nums2
        for (int i = 0; i < nums2Size; i++) {
            int current = arr2[i];

            while (!st.isEmpty() && st.peek() > current) {
                st.pop();
            }

            if (!st.isEmpty()) {
                nextSmaller[current] = st.peek();
            } else {
                nextSmaller[current] = -1;
            }

            st.push(current);
        }

        // Print next smaller elements for elements in nums1
        for (int i = 0; i < nums1Size; i++) {
            if (nextSmaller.find(arr1[i]) != nextSmaller.end()) {
                cout << nextSmaller[arr1[i]] << " ";
            } else {
                cout << -1 << " ";
            }
        }
    }
};

int main() {
    int nums1Size, nums2Size;

    cout << "Enter the size of nums1: ";
    cin >> nums1Size;
    int arr1[nums1Size];
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < nums1Size; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of nums2: ";
    cin >> nums2Size;
    int arr2[nums2Size];
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < nums2Size; i++) {
        cin >> arr2[i];
    }

    Stack s(nums2Size);
    cout << "Next smaller Elements for nums1: ";
    s.nextSmallerEle(arr1, arr2, nums1Size, nums2Size);
    cout << endl;

    return 0;
}