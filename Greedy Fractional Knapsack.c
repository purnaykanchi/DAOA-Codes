#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return item2->ratio - item1->ratio;
}
double fractional_knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare_items);
    double total_value = 0.0;
    int remaining_capacity = capacity;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining_capacity) {
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            double fraction = (double)remaining_capacity / items[i].weight;
            total_value += fraction * items[i].value;
            break;
        }
    }
    return total_value;
}
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    double maximum_value = fractional_knapsack(items, n, capacity);
    printf("Maximum profit achievable: %.2lf\n", maximum_value);
    return 0;
}