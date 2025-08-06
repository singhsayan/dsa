#include<iostream>
#include<vector>
#include <utility>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

TreeNode* buildTree(TreeNode* root){
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    cout << "Enter data to be inserted at the left side of the node:"<< data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data to be inserted at the right side of the node:"<< data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int treeHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftSubtree = treeHeight(root -> left);
    int rightSubtree = treeHeight(root -> right);

    int maxSubTree = max(leftSubtree, rightSubtree) + 1;

    return maxSubTree;
}

pair<int, int> diameterOfTree(TreeNode* root){
        if(root == NULL){
            pair<int, int> d = make_pair(0,0);
            return d;
        }

        pair<int,int> left = diameterOfTree(root -> left);
        pair<int, int> right = diameterOfTree(root -> right);

        bool leftDia = left.first;
        bool rightDia = right.first;
        bool combDia = left.second + right.second + 1; 

        pair<int, int> ans;
        ans.first = max(leftDia, (rightDia,combDia));
        ans.second = max(left.second, left.first);

        return ans;
}

pair<bool,int> balancedOrNot(TreeNode* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // first checks whethe balanced or not and 2nd stores height
    pair<bool,int> left = balancedOrNot(root -> left);
    pair<bool, int> right = balancedOrNot(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
    
}
bool isIdentical(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t2 == NULL){
        return true;
    }
    if(t1 != NULL && t2 == NULL){
        return false;
    }

    if(t1 == NULL && t2 != NULL){
        return false;
    }

    bool leftSubTree = isIdentical(t1 -> left, t2 -> left);
    bool rightSubTree = isIdentical(t1 -> right, t2 -> right);
    bool val = t1 -> data == t2 -> data;

    if(leftSubTree && rightSubTree && val){
        return true;
    }
    else{
        return false;
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;

    if(root == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        

        int size = q.size();
        vector<int> ans(size);

        for(int i = 0; i< size; i++){
            TreeNode* frontNode = q.front();
            q.pop();

            
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if(frontNode -> left){
                q.push(frontNode -> left);
            }
            if(frontNode -> right){
                q.push(frontNode -> right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(ans); 
    }
    return result;
}

void traverseLeft(TreeNode* root, vector<int> &ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    ans.push_back(root->data);

    if (root->left) {
        traverseLeft(root->left, ans);
    } 
    else if (root->right) {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(TreeNode* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode* root, vector<int> &ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    if (root->right) {
        traverseRight(root->right, ans);
    } 
    else if (root->left) {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data); // Add after recursion for reverse order
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    ans.push_back(root->data);

    // Traverse the left boundary
    traverseLeft(root->left, ans);

    // Traverse all leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // Traverse the right boundary
    vector<int> rightBoundary;
    traverseRight(root->right, rightBoundary);
    
    // Add the right boundary in reverse order
    ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());

    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, vector<int> > > nodes;

    queue<pair<TreeNode*, pair<int,int>>> q;
    vector<vector<int>> ans;

    if(root == NULL){
        return;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<TreeNode*, pair<int,int>> temp = q.front();
        q.pop();

        TreeNode* frontNode = temp.front();

        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode -> val);

        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, hd - 1, level + 1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, hd + 1, level + 1));
        }


        for(auto i: nodes){
            vector<int> col;
            for(auto j: i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k: j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
    }
    return ans;
}

vector<int> topView(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> topNode; // Map to store the first node at each horizontal distance (hd)
    queue<pair<TreeNode*, int>> q; // Queue to store nodes along with their horizontal distance (hd)

    // Initialize queue with root and horizontal distance 0
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();

        TreeNode* frontNode = temp.first;
        int hd = temp.second;

        // If no node has been added at this horizontal distance, add it to the map
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        // If the node has a left child, push it with hd - 1
        if (frontNode->left) {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        // If the node has a right child, push it with hd + 1
        if (frontNode->right) {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // Store the top view nodes from the map into the answer vector
    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
}

vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        map<int, int> topNode;
        queue<pair<Node*, int> > q;
        

        q.push(make_pair(root, 0));

        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            topNode[hd] = frontNode -> data;

            if(frontNode -> left){
                q.push(make_pair(frontNode -> left, hd -1));
            }

            if(frontNode -> right){
                q.push(make_pair(frontNode -> right, hd + 1));
            }
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        return ans;
}

void solve(TreeNode* root, vector<int> &ans, int level){
        // base case
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root -> val);
        }
    
        // we entered into a new level
        solve(root -> right, ans, level + 1);
        solve(root -> left, ans, level + 1);
    
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
