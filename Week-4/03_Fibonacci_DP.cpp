#include <iostream>
using namespace std;

#define MAX 100

long long memo[MAX];

long long fibonacciMemo(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);

    return memo[n];
}

long long fibonacciTab(int n) {
    if (n <= 1) {
        return n;
    }

    long long dp[MAX];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    cout << "Fibonacci using Memoization: "
         << fibonacciMemo(n) << endl;

    cout << "Fibonacci using Tabulation: "
         << fibonacciTab(n) << endl;

    return 0;
}