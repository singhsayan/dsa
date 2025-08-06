#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class Stack {
public:
    int top;
    int size;
    int* arr;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    int peek() {
        return arr[top];
    }

    void push(int val) {
        if (top < size - 1) {
            arr[++top] = val;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    bool empty() {
        return top == -1;
    }
};

void nextGreaterElement(int nums1[], int nums2[], int nums1Size, int nums2Size) {
    unordered_map<int, int> nextGreaterMap;
    Stack s(100);  // Assuming size will not exceed 100

    // Step 1: Find next greater element for each element in nums2
    for (int i = nums2Size - 1; i >= 0; i--) {
        int current = nums2[i];

        // Pop elements from the stack that are smaller than the current element
        while (!s.empty() && s.peek() < current) {
            s.pop();
        }

        // If the stack is not empty, the next greater element is the top of the stack
        if (!s.empty()) {
            nextGreaterMap[current] = s.peek();
        } else {
            nextGreaterMap[current] = -1;
        }

        // Push the current element onto the stack
        s.push(current);
    }

    // Step 2: For each element in nums1, find the next greater element from the map
    for (int i = 0; i < nums1Size; i++) {
        cout << nextGreaterMap[nums1[i]] << " ";
    }
}

int main() {
    int nums1Size, nums2Size;

    // Take input for nums1
    cout << "Enter the size of nums1: ";
    cin >> nums1Size;
    int nums1[nums1Size];
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < nums1Size; i++) {
        cin >> nums1[i];
    }

    // Take input for nums2
    cout << "Enter the size of nums2: ";
    cin >> nums2Size;
    int nums2[nums2Size];
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < nums2Size; i++) {
        cin >> nums2[i];
    }

    cout << "Next Greater Elements for nums1: ";
    nextGreaterElement(nums1, nums2, nums1Size, nums2Size);
    cout << endl;

    return 0;
}