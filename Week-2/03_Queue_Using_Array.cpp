#include <iostream>
using namespace std;

#define MAX 100

int queueArray[MAX];
int front = -1;
int rear = -1;

// Add element to queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue is full." << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queueArray[rear] = value;

    cout << value << " added to queue." << endl;
}

// Remove element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << queueArray[front] << " removed from queue." << endl;

    front++;

    // Reset queue when it becomes empty
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Display queue
void display() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";

    for (int i = front; i <= rear; i++) {
        cout << queueArray[i] << " ";
    }

    cout << endl;
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n--- Queue Using Array ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
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