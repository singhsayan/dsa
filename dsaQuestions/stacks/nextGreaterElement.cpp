 #include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap; // To store the next greater element for each element in nums2
        stack<int> s; // Stack to keep track of potential next greater elements

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            
            // Remove elements from the stack that are less than or equal to the current element
            while (!s.empty() && s.top() <= current) {
                s.pop(); // Safely pop because stack is not empty and top <= current
            }
            
            // If stack is not empty, the top element is the next greater element
            if (!s.empty()) {
                nextGreaterMap[current] = s.top();
            } else {
                nextGreaterMap[current] = -1; // No greater element
            }
            
            // Push the current element to the stack
            s.push(current);
        }

        // Create result vector for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }

        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    // Output the result
    for (int num : result) {
        cout << num << " "; // Expected output: -1 3 -1
    }
    cout << endl;

    return 0;
}