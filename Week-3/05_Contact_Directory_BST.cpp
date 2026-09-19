#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string phone;
    Node* left;
    Node* right;
};

Node* createNode(string name, string phone) {
    Node* newNode = new Node();

    newNode->name = name;
    newNode->phone = phone;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, string name, string phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }

    if (name < root->name) {
        root->left = insert(root->left, name, phone);
    }
    else if (name > root->name) {
        root->right = insert(root->right, name, phone);
    }
    else {
        cout << "Contact already exists." << endl;
    }

    return root;
}

Node* search(Node* root, string name) {
    if (root == NULL || root->name == name) {
        return root;
    }

    if (name < root->name) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

Node* findMin(Node* root) {
    Node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteContact(Node* root, string name) {
    if (root == NULL) {
        return root;
    }

    if (name < root->name) {
        root->left = deleteContact(root->left, name);
    }
    else if (name > root->name) {
        root->right = deleteContact(root->right, name);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->name = temp->name;
        root->phone = temp->phone;

        root->right = deleteContact(root->right, temp->name);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->name << " : " << root->phone << endl;

    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int choice;
    string name;
    string phone;

    while (true) {
        cout << "\n--- Contact Directory ---" << endl;
        cout << "1. Insert Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Display Contacts Alphabetically" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter name: ";
                cin >> name;

                cout << "Enter phone number: ";
                cin >> phone;

                root = insert(root, name, phone);

                cout << "Contact inserted." << endl;
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> name;

                {
                    Node* result = search(root, name);

                    if (result != NULL) {
                        cout << "Contact found." << endl;
                        cout << "Name: " << result->name << endl;
                        cout << "Phone: " << result->phone << endl;
                    }
                    else {
                        cout << "Contact not found." << endl;
                    }
                }

                break;

            case 3:
                cout << "Enter name to delete: ";
                cin >> name;

                if (search(root, name) != NULL) {
                    root = deleteContact(root, name);
                    cout << "Contact deleted." << endl;
                }
                else {
                    cout << "Contact not found." << endl;
                }

                break;

            case 4:
                cout << "\nContacts in Alphabetical Order:\n";
                inorder(root);
                break;

            case 5:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}