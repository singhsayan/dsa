#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Definition for a binary tree node as a nested class
    class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        // Default constructor
        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        // Constructor with value
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        // Constructor with value and children
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (current != nullptr || !nodeStack.empty()) {
            // Reach the leftmost node
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }

            // Peek the node at the top of the stack
            current = nodeStack.top();

            // If the right child is null or already visited, process the node
            if (current->right == nullptr || current->right == lastVisited) {
                result.push_back(current->val); // Visit the node
                nodeStack.pop();
                lastVisited = current; // Mark this node as visited
                current = nullptr; // Set current to null to process the next node in stack
            } else {
                // Move to the right child
                current = current->right;
            }
        }

        return result;
    }
};

// Helper function to create a simple tree for testing
Solution::TreeNode* createSampleTree() {
    Solution::TreeNode* root = new Solution::TreeNode(1);
    root->left = new Solution::TreeNode(2);
    root->right = new Solution::TreeNode(3);
    root->left->left = new Solution::TreeNode(4);
    root->left->right = new Solution::TreeNode(5);
    return root;
}

int main() {
    Solution solution;
    Solution::TreeNode* root = createSampleTree();

    vector<int> result = solution.postorderTraversal(root);
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}