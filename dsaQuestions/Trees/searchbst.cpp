#include<iostream>
using namespace std;
#include<queue>
#include<stack>

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

        void insert(node* root, int value){
            if(root == NULL){
                root = new node(value);
                return;
            }
            node* temp = root;
            while(temp != NULL){
                if(temp -> data > value){
                    if(temp -> left == NULL){
                        temp -> left = new node(value);
                        return;
                    }
                    else{
                        temp = temp -> left;
                    }
                    
                }
                else if(temp -> data < value){
                    if(temp -> right == NULL){
                        temp -> right = new node(value);
                        return;
                    }
                    else{
                        temp = temp ->right;
                    }
                    
                }
                else{
                    return;
                }
            }
        }

        node* deleteNode(node* root, int value) {
            if(root == NULL){
                return NULL;
            }

            if (value < root->data) {
                root->left = deleteNode(root->left, value);
            } 
            else if (value > root->data) {
                root->right = deleteNode(root->right, value);
            } 
            else {
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                } 
                else if(root->left == NULL){
                    node* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if(root->right == NULL){
                    node* temp = root->left;
                    delete root;
                    return temp;
                } 
                else{
                    node* minNode = minEle(root->right);
                    root->data = minNode->data;
                    root->right = deleteNode(root->right, minNode->data);
                }
            }
            return root;
        }}

        node* recursiveInsert(node* root, int value){
            if(root == NULL){
                return new node(value);
            }
            if(root -> data > value){
                root -> left =  recursiveInsert(root -> left, value);
            }
            else if(root -> data < value){
                root -> right = recursiveInsert(root -> right, value);
            }
            return root;
        }

        bool searchInBST(node* root, int value){
            if(root == NULL){
                return false;
            }
            if(root -> data == value){
                return true;
            }
            else if(root -> data > value){
                return searchInBST(root -> left, value);
            }
            if(root -> data < value){
                return searchInBST(root -> right, value);
            }
        }


        bool iSearchInBST(node* root, int vaLue){
            while(root != NULL){
                if(root -> data == value){
                    return true;
                }
                if(root -> data > value){
                    root = root -> left;
                }
                if(root -> data < value){
                    root = root -> right;
                }
            }
            return false;
        }
        int maxEle(node* root){
            if(root == NULL){
                return -1;
            }
            while(root -> right != NULL){
                root = root -> right;
            }
            return root -> data;
        }
        int minEle(node* root){
            if(root == NULL){
                return -1;
            }
            while(root -> left != NULL){
                root = root -> left;
            }
            return root -> data;
        }
        void PreAndSuc(node* root, int &pre, int &suc){
            node* temp = root;
            pre = -1;
            suc = -1;
            while(temp != NULL){
                if(temp -> data > value){
                    suc = temp -> data;
                    temp = temp -> left;
                }
                else if(temp -> data < value){
                    pre = temp -> data;
                    temp = temp -> right;
                }
                }
                else{
                    if(temp -> left != NULL){
                        node* leftSubTree = temp -> left;
                        while(leftSubTree -> right != NULL){
                            leftSubTree = leftSubTree -> right;
                        }
                        pre = leftSubTree -> data;
                    }
                
                    if(temp -> right != NULL){
                        node* rightSubTree = temp -> right;
                        while(rightSubTree -> left != NULL){
                            rightSubTree = rightSubTree -> left;
                        }
                    suc = rightSubTree -> data;
                    }
            }
            break;
        }
}



