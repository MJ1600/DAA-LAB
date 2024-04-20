#include<stdio.h>

struct Item {
    int value;
    int weight;
};

int compareItems(const void *a, const void *b) {
    double ratioA = (double)(((struct Item*)a)->value) / (((struct Item*)a)->weight);
    double ratioB = (double)(((struct Item*)b)->value) / (((struct Item*)b)->weight);
    return (ratioB - ratioA);
}

double knapsackGreedy(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &items[i].value, &items[i].weight);

    double maxValue = knapsackGreedy(capacity, items, n);
    printf("Maximum value in knapsack: %.2f\n", maxValue);

    return 0;
}
