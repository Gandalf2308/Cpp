#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        left = NULL;  
        right = NULL; 
    }
};
class BST {
public:
    Node* root;
    BST() { 
        root = NULL;
    }
    Node* insert(Node* node, int key) {
        if (node == NULL) { 
            return new Node(key);
        }
        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        }
        return node;
    }
    void inorder(Node* node) {
        if (node != NULL) { 
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    }
    void preorder(Node* node) {
        if (node != NULL) { 
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void postorder(Node* node) {
        if (node != NULL) { 
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
    }
    Node* search(Node* node, int key) {
        if (node == NULL || node->val == key) { 
            return node;
        }
        if (key < node->val) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }
    void postorder() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
    Node* search(int key) {
        return search(root, key);
    }
};
int main() {
    BST tree;
    int choice;
    int val;
    while (true) {
        cout << "1. Add Root Node\n";
        cout << "2. Insert\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Search\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (tree.root != NULL) { 
                    cout << "Root already exists!" << endl;
                } else {
                    cout << "Enter value for root: ";
                    cin >> val;
                    tree.insert(val);
                }
                break;
            case 2:
                if (tree.root == NULL) { 
                    cout << "Please add a root node first" << endl;
                } else {
                    cout << "Enter value to insert: ";
                    cin >> val;
                    tree.insert(val);
                }
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.preorder();
                break;
            case 5:
                tree.postorder();
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                if (tree.search(val)) {
                    cout <<" found in the BST." << endl;
                } else {
                    cout <<" not found in the BST." << endl;
                }
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0; 
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}