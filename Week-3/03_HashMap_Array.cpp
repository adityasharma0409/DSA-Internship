#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

void insert(int key) {
    int index = key % SIZE;

    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == originalIndex) {
            cout << "Hash table is full." << endl;
            return;
        }
    }

    hashTable[index] = key;

    cout << key << " inserted at index " << index << endl;
}

bool search(int key) {
    int index = key % SIZE;
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return true;
        }

        index = (index + 1) % SIZE;

        if (index == originalIndex) {
            break;
        }
    }

    return false;
}

void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> ";

        if (hashTable[i] == -1) {
            cout << "Empty";
        }
        else {
            cout << hashTable[i];
        }

        cout << endl;
    }
}

int main() {
    initialize();

    int n, key, searchKey;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";

    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(key);
    }

    display();

    cout << "\nEnter key to search: ";
    cin >> searchKey;

    if (search(searchKey)) {
        cout << searchKey << " found in hash table." << endl;
    }
    else {
        cout << searchKey << " not found in hash table." << endl;
    }

    return 0;
}