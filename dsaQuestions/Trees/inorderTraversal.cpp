#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root){
    int data;
    cout << "Enter data you want to insert:" << endl;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout << "Do you want to insert any node at the left of root node:"<< data << "?" << endl;
    root -> left = buildTree(root -> left);

    cout << "Do you want to insert any node at the right of root node:"<< data << "?" << endl;
    root -> right = buildTree(root -> right);


    return root;
}

void inorder(node* root){

    if(root == NULL){
        return;
    }

    inorder(root -> left);

    cout << root -> data << " " << endl;

    inorder(root -> right);

}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    
    cout << root -> data << " " << endl;

    preorder(root -> left);

    preorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);

    postorder(root -> right);

    cout << root -> data<< " " << endl;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    int data;
    cout << "Enter data for node:" << endl;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);

        }


        cout << "Enter data for right node of " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> left = new node(rightData);
            q.push(temp -> right);

        }
    }
}

void iInorder(node* root){

    stack<node*> s;
    node* temp = root;

    while(temp != NULL || !s.empty()){
        while(temp != NULL){
            s.push(temp);
            temp = temp -> left;
        }

        temp = s.top();
        s.pop();

        cout << temp -> data << " " << endl;

        temp = temp -> right;

    }
    cout << endl;

}

oid iPreorder(node* root) {
    if (root == nullptr) return; // Check for empty tree

    stack<node*> s;
    s.push(root);

    while (!s.empty()) {
        node* temp = s.top(); // Get the top node
        s.pop();              // Remove the top node from the stack

        cout << temp->data << " "; // Process the node (visit it)

        // Push right child first so that left child is processed first
        if (temp->right) {
            s.push(temp->right);
        }
        if (temp->left) {
            s.push(temp->left);
        }
    }
}
void postorderOneStack(node* root){

    node* temp = root;
    node* lastVisited = NULL;
    stack<node*> s;

    while(temp != NULL || !s.empty()){
        while(temp != NULL){
            s.push(temp);
            temp = temp -> left;
        }
    }

    temp = s.top();

    // If the right child is NULL or already visited, visit the node
    if (temp->right == NULL || temp->right == lastVisited) {
        cout << temp->data << " ";
        s.pop();
        lastVisited = temp;
        temp = NULL; // Reset temp to continue with the next node in the stack
    } 
    else {
        // Otherwise, move to the right child
        temp = temp->right;
    }
    cout << endl;
    
}

void postOrderTwoStack(node* root) {
    if (root == NULL) return;

    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        // Pop a node from s1 and push it onto s2
        node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        // Push the left and right children of the popped node onto s1
        if (temp->left) {
            s1.push(temp->left);
        }
        if (temp->right) {
            s1.push(temp->right);
        }
    }

    // Now s2 contains the nodes in post-order sequence
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

int height(node* root){

    if(root == NULL){
        return 0;
    }

    int leftCount = height(root -> left);
    int rightCount = height(root -> right);

    return max(leftCount, rightCount) + 1;
}

pair<bool, int> balanced(node* root){
    node* temp = root;

    if(temp == NULL){
        pair<bool, int>  p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balanced(temp -> left);
    pair<bool, int> right = balanced(temp -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.first = leftAns && rightAns && diff;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

bool isBalanced(node* root){
    balanced(root).first;
}

pair<int,int> diameter(node* root){
    if(root == NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftDia = diameter(root -> left);
    pair<int,int> rightDia = diameter(root -> right);

    int op1 =  leftDia.first;
    int op2 = rightDia.first;
    int op3 = leftDia.second + rightDia.second;

    pair<int,int> ans;
    
    ans.first = max(op1, max(op2,op3));
    ans.second = max(leftDia.second, rightDia.second) + 1;
}

bool identicalTree(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }

    return (root1 -> data == root2 -> data && identicalTree(root1 -> left, root2 -> left) && identicalTree(root2 -> right, root1 -> right));
}

vector<int> zigZag(node* root){

    bool leftToRight = true;

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size); // Create a temporary vector to store nodes at the current level

        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            level[index] = temp -> data;

            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
        
        // Append the current level to the answer
        ans.insert(ans.end(), level.begin(), level.end());

        leftToRight =! leftToRight;        
    }
    return ans;

    void topView(node *root, int *ans, int &minHD, int &maxHD) {
        if (root == NULL) {
            return;
        }

        map<int, int> topNode; // To store the top-most node at each horizontal distance
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()){
            pair<node*, int> temp = q.front();
            q.pop();

            node *frontNode = temp.first;
            int hd = temp.second;

            // If one value is present for horizontal distance, do nothing
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = frontNode->data;
                minHD = min(minHD, hd);
                maxHD = max(maxHD, hd);
            }

            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        // Transfer the map elements to the ans array
        int index = 0;
        for (int i = minHD; i <= maxHD; i++) {
            ans[index++] = topNode[i];
        }
    }

    void solve(node* root, int* ans, int &maxLevel, int level, int &index) {
        // Base case
        if (root == NULL) {
            return;
        }

        // If this is the first node of the current level, add it to the result
        if (level > maxLevel) {
            ans[index++] = root->val;
            maxLevel = level;
        }

        // Recursive calls for right and left subtrees
        solve(root->right, ans, maxLevel, level + 1, index);
        solve(root->left, ans, maxLevel, level + 1, index);
    }

    void rightSideView(node* root, int* ans, int &size) {
        int maxLevel = -1; // Tracks the maximum level visited
        int index = 0;     // Tracks the position in the result array
        solve(root, ans, maxLevel, 0, index);
        size = index;      // Update size with the number of elements in the result
    }


    bool isSymmetric(node* root) {
        if (root == NULL) return true; // Base case: an empty tree is symmetric
        
        // Helper variables for the iterative approach
        stack<TreeNode*> leftStack, rightStack;
        leftStack.push(root->left);
        rightStack.push(root->right);
        
        while (!leftStack.empty() && !rightStack.empty()) {
            TreeNode* leftNode = leftStack.top();
            TreeNode* rightNode = rightStack.top();
            leftStack.pop();
            rightStack.pop();
            
            // Check if both nodes are null
            if (leftNode == NULL && rightNode == NULL) continue;
            // Check if one of the nodes is null or if values are different
            if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val) {
                return false;
            }
            
            // Push children to stacks in the order that mirrors the tree
            leftStack.push(leftNode->left);
            leftStack.push(leftNode->right);
            rightStack.push(rightNode->right);
            rightStack.push(rightNode->left);
        }
        
        return leftStack.empty() && rightStack.empty();
        
    }
}




int main(){
    node* root = NULL;
    root = buildTree(root);

    cout << "Inorder Traversal of the Tree:" << endl;
    inorder(root);


    cout << "Preorder traversal of the tree is:" << endl;
    preorder(root);
    

    cout << "Postorder Traversal of the Tree:" << endl;
    postorder(root);
}