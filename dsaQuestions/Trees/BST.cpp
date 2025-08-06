#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node* first;
    Node* second;
    Node* previous;
    int data;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this -> first = NULL;
        this -> second = NULL;
        this -> previous = NULL;
    }

    void insert(Node* root, int value) {
        if (root == NULL) {
            Node* nnode = new Node(value);
            root = nnode;
            return;
        }
        Node* temp = root;
        while (temp != NULL) {
            if (value > root->data) {
                if (temp->right == NULL) {
                    temp->right = new Node(value);
                } else {
                    temp = temp->right;
                }
            } else if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = new Node(value);
                } else {
                    temp = temp->left;
                }
            } else {
                return;
            }
        }
    }

    Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        // If the tree is empty or we reach a null node
        return NULL;
    }

    if (root->data == value) {
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Only right child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: Only left child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 4: Two children
        else {
            Node* minVal = min(root->right); // Find the minimum value in the right subtree
            root->data = minVal->data;      // Replace root's value with successor's value
            root->right = deleteNode(root->right, minVal->data); // Recursively delete successor
        }
    }
    else if (value < root->data) {
        // If the value to delete is smaller, recurse on the left subtree
        root->left = deleteNode(root->left, value);
    }
    else {
        // If the value to delete is larger, recurse on the right subtree
        root->right = deleteNode(root->right, value);
    }

    return root; // Return the (potentially updated) root of the tree
}


    void search(Node* root, int val) {
        Node* temp = root;

        if (temp->data == val) {
            cout << "Value present in BST" << endl;
            return;
        } 
        else if (temp->data < val) {
            search(temp->left, val);
        } else {
            search(temp->right, val);
        }
    }

    Node* min(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* max(Node* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    int ceil(Node* root, int value) {
        Node* temp = root;
        int ceilValue = -1;
        while (temp != NULL) {
            if (value > temp->data) {
                temp = temp->right;
            } else {
                ceilValue = temp->data;
                temp = temp->left;
            }
        }
        return ceilValue;
    }

    int floor(Node* root, int value) {
        Node* temp = root;
        int floorValue = -1;
        while (temp != NULL) {
            if (value < temp->data) {
                temp = temp->left;
            } else {
                floorValue = temp->data;
                temp = temp->right;
            }
        }
        return floorValue;
    }

    int result(Node* root, int& i, int k) {
        if (root == NULL) {
            return -1;
        }
        int left = result(root->left, i, k);
        if (left != -1) {
            return left;
        }

        i++;
        if (i == k) {
            return root->data;
        }

        return result(root->right, i, k);
    }

    int kthSmallest(Node* root, int k) {
        int i = 0;
        return result(root, i, k);
    }

    bool isBST(Node* temp, long long mini, long long maxi) {
        if (temp == NULL) {
            return true;
        } else if (temp->data > mini && temp->data < maxi) {
            bool left = isBST(temp->left, mini, temp->data);
            bool right = isBST(temp->right, temp->data, maxi);
            return left && right;
        } else {
            return false;
        }
    }

    bool isValidBST(Node* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }

    Node* lca(Node* root, Node* p, Node* q) {
        if (root == NULL) {
            return NULL;
        }
        while (root != NULL) {
            if (root->data < p->data && root->data < q->data) {
                root = root->right;
            } else if (root->data > p->data && root->data > q->data) {
                root = root->left;
            } else {
                return root;
            }
        }
        return NULL;
    }

    void inorder(Node* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

    bool twoSum(Node* root, int target) {
        if (root == NULL) {
            return false;
        }
        vector<int> in;
        inorder(root, in);

        int i = 0;
        int j = in.size() - 1;

        while (i <= j) {
            if (in[i] + in[j] == target) {
                return true;
            } else if (in[i] + in[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }

    void Inorder(Node* root) {
        if (root == NULL) {
            return;
        }

        Inorder(root->left);

        if (previous && root->data < previous->data) {
            if (!first) {
                first = previous;
            }
            second = root;
        }

        previous = root;

        Inorder(root->right);
    }

    void recoverTree(Node* root) {
        Inorder(root);

        if (first && second) {
            swap(first->data, second->data);
        }
    }
};

int main() {
    Node* root = NULL;
    int choice, value, k;

    cout << "Binary Search Tree Operations" << endl;
    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Find Kth Smallest\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            if (root == NULL) {
                root = new Node(value);
            } else {
                root->insert(root, value);
            }
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            root->search(root, value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            root->deleteNode(root, value);
            break;

        case 4:
            cout << "Enter k for Kth smallest: ";
            cin >> k;
            cout << "The " << k << "th smallest value is: " << root->kthSmallest(root, k) << endl;
            break;

        case 5:
            exit(0);
        }
    }

    return 0;
}