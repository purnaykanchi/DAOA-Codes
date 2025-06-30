#include <stdio.h>
#include <stdlib.h>
int containerLoading(int weights[], int n, int capacity) {
    int bins = 0;
    int* bin_rem = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bins; j++) {
            if (bin_rem[j] >= weights[i]) {
                bin_rem[j] -= weights[i];
                break;
            }
        }
        if (j == bins) {
            bin_rem[bins] = capacity - weights[i];
            bins++;
        }
    }
    free(bin_rem);
    return bins;
}int main() {
    int weights[] = {2, 5, 4, 7, 1, 3, 8};
    int n = sizeof(weights)/sizeof(weights[0]);
    int capacity = 10;
    printf("Number of bins required: %d\n", containerLoading(weights, n, capacity));
    return 0;
}