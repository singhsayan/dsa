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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val);

            // Push right child first so that left is processed first
            if (current->right) {
                nodeStack.push(current->right);
            }
            if (current->left) {
                nodeStack.push(current->left);
            }
        }

        return result;
    }
};

// Helper function to create a simple tree for testing
Solution::TreeNode* createSampleTree() {
    Solution::TreeNode* root = new Solution::TreeNode(1);
    root->right = new Solution::TreeNode(2);
    root->right->left = new Solution::TreeNode(3);
    return root;
}

int main() {
    Solution solution;
    Solution::TreeNode* root = createSampleTree();
    
    vector<int> result = solution.preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}