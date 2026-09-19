#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push element into stack
void push(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << value << " pushed into stack." << endl;
}

// Pop element from stack
void pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* temp = top;

    cout << top->data << " popped from stack." << endl;

    top = top->next;

    delete temp;
}

// Display stack
void display() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* temp = top;

    cout << "Stack: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n--- Stack Using Linked List ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
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