#include <stdio.h>

struct Item {
    int value, weight;
};

void knapsackGreedy(int n, struct Item items[], int capacity) {
    float ratio[n], totalValue = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        ratio[i] = (float)items[i].value / items[i].weight;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsackGreedy(n, items, capacity);

    return 0;
}
