#include <iostream>
#define nullptr NULL
using namespace std;

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    Node *left;
    Node *right;

    // Constructor for creating a new node with a given value
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to recursively traverse the binary search tree in-order and print the values of each node
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to search for a value in the binary search tree
Node* search(Node* root, int val) {
    // If the root node is null or the value is found at the root, return the root
    if (root == nullptr || root->data == val) {
        return root;
    }
    // If the value is less than the root's value, search the left subtree
    if (val < root->data) {
        return search(root->left, val);
    }
    // If the value is greater than the root's value, search the right subtree
    return search(root->right, val);
}

// Main function to create and manipulate the binary search tree
int main() {
    // Initialize a null root node
    Node* root = nullptr;
    // Insert several values into the binary search tree
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(25);
    root->left->right->right = new Node(45);
    
    // Print the in-order traversal of the tree
    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;
    
    // Ask the user for a value to search for
    int val;
    cout << "Enter a value to search for: ";
    cin >> val;
    
    // Search for the value in the tree
    Node* node = search(root, val);
    if (node == nullptr) {
        cout << "Value not found in the tree" << endl;
    } else {
        cout << "Value found in the tree" << endl;
    }
    
    return 0;
}


