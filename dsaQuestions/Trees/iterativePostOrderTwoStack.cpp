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
        if (root == nullptr) {
            return result; // Return empty if the tree is empty
        }

        stack<TreeNode*> stack1, stack2;
        stack1.push(root);

        // Process nodes using two stacks
        while (!stack1.empty()) {
            TreeNode* current = stack1.top();
            stack1.pop();
            stack2.push(current); // Push the current node to stack2

            // Push left and right children to stack1
            if (current->left) {
                stack1.push(current->left);
            }
            if (current->right) {
                stack1.push(current->right);
            }
        }

        // Now pop from stack2 to get the postorder
        while (!stack2.empty()) {
            result.push_back(stack2.top()->val);
            stack2.pop();
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


	// 1.	First Stack (stack1): This stack is used to traverse the tree in a manner similar to preorder. You push the root node onto stack1, and then while stack1 is not empty:
	// •	Pop the top node.
	// •	Push this node onto stack2.
	// •	Push its left child first (if it exists) onto stack1, followed by the right child (if it exists). This ensures that the left child is processed before the right child.
	// 2.	Second Stack (stack2): After processing all nodes into stack2, this stack will have the nodes in the order of their postorder traversal. The final step involves popping nodes from stack2 and pushing their values onto the result vector.