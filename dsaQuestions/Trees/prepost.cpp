#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        preIndex = 0;
        postIndex = 0;
        return buildTree(preorder, postorder);
    }

private:
    int preIndex, postIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (root->val != postorder[postIndex]) {
            root->left = buildTree(preorder, postorder);
        }
        if (root->val != postorder[postIndex]) {
            root->right = buildTree(preorder, postorder);
        }
        
        postIndex++;  // Move postIndex forward as we have completed this subtree
        return root;
    }
};

// Helper function to print the inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Solution solution;
    TreeNode* root = solution.constructFromPrePost(preorder, postorder);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);

    return 0;
}