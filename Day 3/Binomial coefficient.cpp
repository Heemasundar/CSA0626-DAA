#include <stdio.h>

int binomialCoeff(int n, int k) {
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    if (k > n || n < 0 || k < 0) {
        printf("Invalid input. Ensure 0 <= k <= n.\n");
        return 1;
    }

    printf("C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));

    return 0;
}
