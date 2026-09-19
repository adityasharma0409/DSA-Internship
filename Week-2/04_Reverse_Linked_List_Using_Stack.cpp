#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct StackNode {
    int data;
    StackNode* next;
};

Node* head = NULL;
StackNode* top = NULL;

// Insert node into linked list
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
}

// Push value into stack
void push(int value) {
    StackNode* newNode = new StackNode();

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop value from stack
int pop() {
    StackNode* temp = top;

    int value = top->data;

    top = top->next;

    delete temp;

    return value;
}

// Display linked list
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Reverse linked list using stack
void reverseUsingStack() {
    if (head == NULL) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* temp = head;

    // Push all linked list values into stack
    while (temp != NULL) {
        push(temp->data);
        temp = temp->next;
    }

    // Put values back into linked list
    temp = head;

    while (temp != NULL) {
        temp->data = pop();
        temp = temp->next;
    }
}

int main() {
    int n;
    int value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "\nOriginal Linked List: ";
    display();

    reverseUsingStack();

    cout << "Reversed Linked List: ";
    display();

    return 0;
}