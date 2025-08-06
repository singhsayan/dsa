#include<iostream>
#include<stack>
#include<queue>
using namespcae std;

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

void levelOrderTraversal(node* root){

    int data;
    cout << "Enter data for the root node:" << endl;
    cin >> data;

    node* current = new node(data);

    queue<node*> q;
    q.push(current);

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        cout << "Enter data for the left part of the root node:" << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            front -> left = new node(leftData);
            q.push(front -> left);
        }

        cout << "Enter data for the right part of the root node:" << endl;
        int rightData;
        cin >> leftData;

        if(rightData != -1){
            front -> right = new node(rightData);
            q.push(front -> right);
        }
    }
}

node* SearchInBST(node* root, int value){
    if(root -> data == NULL){
        return NULL;
    }
    else if(root -> data == value){
        return root;
    }

    else if(root -> data > value){
        return isBST(root -> left, value);
    }

    else{
        return isBST(root -> right, value);
    }
}

node* iSearchInBST(node* root, int value){
    if(root -> data == NULL){
        return NULL;
    }

    while(root != NULL){
        if(value == root -> data){
            return root;
        }
        else if(root -> data > value){
                root = root -> left;
        }
        else{
                root = root -> right;
        }
    }
    return NULL;

}

node* min(node* root){
    while(root != NULL){
        root = root -> left;
    }
    return root;
}

node* max(node* root){
    while(root != NULL){
        root = root -> right;
    }
    return root;
}

node* ceil(node* root, int value){

    if(root -> data == NULL){
        return NULL;
    }

    int ceil = -1;

    while(root != NULL){
        if(root -> data == value){
            return root -> data;
        }
        else if(root -> data > value){
            ceil = root -> data;
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
}

node* floor(node* root, int value){

    if(root -> data == NULL){
        return NULL;
    }

    int floor = -1;

    while(root != NULL){
        if(root -> data == value){
            return root -> data;
        }
        else if(root -> data > value){
            root = root -> left;
        }
        else{
            floor = root -> data;
            root = root -> right;
        }
    }
}

node* insertNode(node* root, int value){
    if(root -> data == NULL){
        root = new node(value);
        return root;
    } 
    else if(root -> data > value){
        root -> right = insertNode(root -> right, value);
    }
    else{
        root -> left = insertNode(root -> left, value);
    }
    return root;
}

node* deleteNode(node* root, int key){
    if(root -> data == key){
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        else if(root -> left == NULL && root -> right != NULL){
            node* temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL && root -> left != NULL){
            node* temp = root -> left;
            delete root;
            return temp;
        }
        else{
            node* minVal = min(root -> right);
            root -> data = minVal -> data;

            root -> right = deleteNode(root -> right, minNode -> data);
            return root;
        }
    }

    else if(root -> data > key){
        root -> left = deleteNode(root -> left, key);
    }
    else{
        root -> right = deleteNode(root -> right, key);
    }
    
}

int solve(node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }

    int left = solve(root -> left, i, k);

    if(left != -1){
        return left;
    }

    i++;
    if(i == k){
        return root -> data;
    }
    
    return solve(root -> right, i, k);
}

int kthSmallest(node* root, int k){
    int i = 0;
    return solve(root, i, k);
}

bool isBST(node* root, long long mini, long long maxi){
    if(root == NULL){
        return true;
    }
    
    if(root -> data > mini && root -> data < maxi){
        bool left = isBST(root -> left, mini, root -> data);
        bool right = isBST(root -> right, root -> data, maxi);
        return left && right;
    }
    else return false;
}

bool isValidBST(node* root){
    return isBST(root, INT_MIN, INT_MAX);
}

node* LCA(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root -> data > a && root -> data > b){
        root = root -> left;
    }
    else if(root -> data < a && root -> data < b){
        root = root -> right;
    }
    else{
        return root;
    }
    return NULL;
}

node* result(vector,int> result, long long mini, long long maxi, int &i){

    if(i >= preorder.size()){
        return NULL;
    }

    if(mini > preorder[i] || maxi < preorder[i]){
        return NULL;
    }

    node* root = new node(preorder[i++]);
    root -> left = result(root -> left, mini, root -> data, i);
    root -> right = result(root -> right, root -> data, maxi, i);

    return root;


}

node* BSTFromPreOrder(vector<int> *preorder){
    int maxi = INT_MAX;
    int mini = INT_MIN;

    int i = 0;
    return result(preorder, mini, maxi, i);
}

void inoderSucPreorderPre(node* root, int key){
    node* suc;
    node* pre;
    while(root && root -> data != key){
        if(root -> data > key){
            suc = root -> data;
            root = root -> left;
        }
        else{
            pre = root -> data;
            root = root -> right;
        }
    }

    if(root){
        if(root -> left){
            node* leftTree = root -> left;
            while(root -> right){
                leftTree = leftTree -> right;
            }
            pre = leftTree;
        }

        if(root -> right){
            node* rightTree = root -> right;
            while(root -> left){
                rightTree = rightTree -> left;
            }
            suc = rightTree;
        }
    }
}

int main(){

}