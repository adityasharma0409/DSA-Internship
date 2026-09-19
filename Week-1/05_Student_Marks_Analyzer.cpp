#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 3) {
        cout << "At least 3 students are required." << endl;
        return 0;
    }

    int marks[n];

    cout << "Enter marks of students: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    // Bubble Sort in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (marks[j] < marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    // Calculate average
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }

    double average = (double)sum / n;

    cout << "\nTop 3 Marks:" << endl;
    cout << "1. " << marks[0] << endl;
    cout << "2. " << marks[1] << endl;
    cout << "3. " << marks[2] << endl;

    cout << "\nAverage Score: " << average << endl;

    return 0;
}