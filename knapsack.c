#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    float ratio; // value-to-weight ratio
};

// Function to calculate value-to-weight ratio for each item
void calculateRatio(struct Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
}

// Comparison function to sort by value-to-weight ratio (descending order)
int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;

    // Compare based on the ratio (larger ratio should come first)
    if (itemA->ratio < itemB->ratio) return 1;  // itemB comes before itemA
    if (itemA->ratio > itemB->ratio) return -1; // itemA comes before itemB
    return 0; // both are equal
}

// Greedy Knapsack function
void greedyKnapsack(struct Item items[], int n, int W) {
    int totalValue = 0;
    int totalWeight = 0;
    
    // Sort items by value-to-weight ratio using qsort
    qsort(items, n, sizeof(struct Item), compare);

    // Display sorted items based on the value-to-weight ratio
    printf("Item No. | Value | Weight | Value/Weight Ratio\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("   %d    |  %d   |   %d   |     %.2f\n", i+1, items[i].value, items[i].weight, items[i].ratio);
    }
    printf("\n");

    // Select items for the knapsack
    printf("Selected Items: \n");
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d (Value: %d, Weight: %d) added.\n", i + 1, items[i].value, items[i].weight);
        }
    }

    // Final result
    printf("\nTotal value of selected items: %d\n", totalValue);
    printf("Total weight of selected items: %d\n", totalWeight);
}

int main() {
    int n, W;

    // Input number of items and knapsack capacity
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of the knapsack: ");
    scanf("%d", &W);

    struct Item items[n];

    // Input value and weight for each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate the value-to-weight ratio for each item
    calculateRatio(items, n);

    // Call the greedy knapsack function
    greedyKnapsack(items, n, W);

    return 0;
}
