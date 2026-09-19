#include <iostream>
#include <string>
using namespace std;

#define MAX 100

string undoStack[MAX];
string redoStack[MAX];

int undoTop = -1;
int redoTop = -1;

// Push action into undo stack
void pushUndo(string action) {
    if (undoTop == MAX - 1) {
        cout << "Undo stack is full." << endl;
        return;
    }

    undoTop++;
    undoStack[undoTop] = action;

    // New action clears redo history
    redoTop = -1;
}

// Undo last action
void undo() {
    if (undoTop == -1) {
        cout << "Nothing to undo." << endl;
        return;
    }

    string action = undoStack[undoTop];

    undoTop--;

    redoTop++;
    redoStack[redoTop] = action;

    cout << "Undo: " << action << endl;
}

// Redo last undone action
void redo() {
    if (redoTop == -1) {
        cout << "Nothing to redo." << endl;
        return;
    }

    string action = redoStack[redoTop];

    redoTop--;

    undoTop++;
    undoStack[undoTop] = action;

    cout << "Redo: " << action << endl;
}

// Display current stacks
void display() {
    cout << "\nUndo Stack: ";

    if (undoTop == -1) {
        cout << "Empty";
    }
    else {
        for (int i = 0; i <= undoTop; i++) {
            cout << undoStack[i] << " | ";
        }
    }

    cout << "\nRedo Stack: ";

    if (redoTop == -1) {
        cout << "Empty";
    }
    else {
        for (int i = 0; i <= redoTop; i++) {
            cout << redoStack[i] << " | ";
        }
    }

    cout << endl;
}

int main() {
    int choice;
    string action;

    while (true) {
        cout << "\n--- Undo-Redo Text Editor ---" << endl;
        cout << "1. Perform Action" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Display Stacks" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter action: ";
                cin.ignore();
                getline(cin, action);

                pushUndo(action);

                cout << "Action performed: " << action << endl;
                break;

            case 2:
                undo();
                break;

            case 3:
                redo();
                break;

            case 4:
                display();
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