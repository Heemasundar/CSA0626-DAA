#include <stdio.h>
#include <limits.h>

#define MAX 16
#define INF INT_MAX

int dp[MAX][1 << MAX];
int dist[MAX][MAX];
int n;

int tsp(int start) {
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[i][mask] = INF;
        }
    }

    dp[start][1 << start] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if (!(mask & (1 << v)) && dist[u][v] != INF) {
                        int new_cost = dp[u][mask] + dist[u][v];
                        if (new_cost < dp[v][mask | (1 << v)]) {
                            dp[v][mask | (1 << v)] = new_cost;
                        }
                    }
                }
            }
        }
    }

    int result = INF;
    for (int i = 0; i < n; i++) {
        if (i != start && dist[i][start] != INF) {
            int final_cost = dp[i][(1 << n) - 1] + dist[i][start];
            if (final_cost < result) {
                result = final_cost;
            }
        }
    }

    return result;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int start = 0;
    printf("Minimum cost of TSP: %d\n", tsp(start));

    return 0;
}
