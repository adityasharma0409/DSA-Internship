#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert a node at the end
void insert(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << value << " inserted successfully." << endl;
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        cout << "Linked List is empty." << endl;
        return;
    }

    // If first node needs to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << value << " deleted successfully." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << value << " not found." << endl;
    }
    else {
        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << value << " deleted successfully." << endl;
    }
}

// Display the linked list
void display() {
    if (head == NULL) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n--- Singly Linked List ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}