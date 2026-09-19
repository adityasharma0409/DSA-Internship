#include <iostream>
using namespace std;

int main() {
    int n;
    int capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[20];
    int value[20];

    cout << "Enter weights:\n";

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[21][101] = {0};

    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= capacity; w++) {

            if (weight[i - 1] <= w) {

                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                if (include > exclude) {
                    dp[i][w] = include;
                }
                else {
                    dp[i][w] = exclude;
                }
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: " << dp[n][capacity] << endl;

    return 0;
}