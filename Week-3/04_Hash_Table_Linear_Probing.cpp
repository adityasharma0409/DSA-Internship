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

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

void display() {
    cout << "\nHash Table using Linear Probing:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << " : ";

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

    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys: ";

    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(key);
    }

    display();

    return 0;
}