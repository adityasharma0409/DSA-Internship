#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

int main() {
    Node* root = NULL;
    int n, value, searchValue;

    cout << "Enter number of values: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter value to search: ";
    cin >> searchValue;

    if (search(root, searchValue)) {
        cout << searchValue << " found in BST." << endl;
    }
    else {
        cout << searchValue << " not found in BST." << endl;
    }

    return 0;
}