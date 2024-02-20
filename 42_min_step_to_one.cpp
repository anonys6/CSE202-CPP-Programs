#include <iostream>
#include <vector>

using namespace std;

int minStepsUsingMemoHelper(int n, int memo[]) {
    if (n == 1) {
        return 0;
    }

    if (n == 2 || n == 3) {
        return 1;
    }

    if (memo[n] != -1) {

        return memo[n];
    }

    int minusOne = 10000, divideByTwo = 10000, divideByThree = 10000;

    minusOne = minStepsUsingMemoHelper(n - 1, memo);

    if (n % 2 == 0) {
        divideByTwo = minStepsUsingMemoHelper(n / 2, memo);
    }

    if (n % 3 == 0) {
        divideByThree = minStepsUsingMemoHelper(n / 3, memo);
    }

    memo[n] = 1 + min(minusOne, min(divideByTwo, divideByThree));

    return memo[n];
}

int minStepsUsingMemo(int n) {

    int memo[n + 1];

    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    return minStepsUsingMemoHelper(n, memo);
}

int minStepsUsingDp(int n) {

    if (n == 1) {
        return 0;
    }

    if (n == 2 || n == 3) {
        return 1;
    }

    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {

        int minStep = dp[i - 1];

        if (i % 2 == 0) {
            minStep = min(minStep, dp[i / 2]);
        }

        if (i % 3 == 0) {
            minStep = min(minStep, dp[i / 3]);
        }

        dp[i] = 1 + minStep;
    }

    return dp[n];
}

int minSteps(int n) { return minStepsUsingDp(n); }

int minStepNumSquaresRecursive(int n) {

    if (n == 0) {
        return 0;
    }

    int minSteps = 10000;

    for (int i = 1; i * i <= n; i++) {
        minSteps = min(minSteps, 1 + minStepNumSquaresRecursive(n - i * i));
    }

    return minSteps;
}

int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int dp[m][n];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int n;
    cin >> n;

    cout << minSteps(n);

    return 0;
}