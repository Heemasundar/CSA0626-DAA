#include <stdio.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int u, int v) {
    parent[u] = v;
}

void kruskal(int n, int e) {
    struct Edge temp;
    int i, j, u, v, minCost = 0;

    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in the MST:\n");
    for (i = 0; i < e; i++) {
        u = find(edges[i].src);
        v = find(edges[i].dest);

        if (u != v) {
            printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            minCost += edges[i].weight;
            unionSets(u, v);
        }
    }

    printf("Minimum cost of the MST: %d\n", minCost);
}

int main() {
    int n, e, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter source, destination, and weight of each edge:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(n, e);

    return 0;
}
