#include <stdio.h>
#include <stdbool.h>
#define MAX_SUBSETS 5
#define MAX_ELEMENTS 10
void setCover(bool subsets[MAX_SUBSETS][MAX_ELEMENTS], int numSubsets, int numElements) {
    bool covered[MAX_ELEMENTS] = {false};
    int cover[MAX_SUBSETS] = {0};
    int coverSize = 0;
    while (true) {
        int maxUncovered = 0;
        int selectedSubset = -1;
        for (int i = 0; i < numSubsets; i++) {
            if (cover[i]) continue;
            int uncovered = 0;
            for (int j = 0; j < numElements; j++) {
                if (!covered[j] && subsets[i][j]) {
                    uncovered++;
                }
            }
            if (uncovered > maxUncovered) {
                maxUncovered = uncovered;
                selectedSubset = i;
            }
        }
        if (selectedSubset == -1) break;
        cover[selectedSubset] = 1;
        coverSize++;
        for (int j = 0; j < numElements; j++) {
            if (subsets[selectedSubset][j]) {
                covered[j] = true;
            }
        }
    }
    printf("Selected subsets: ");
    for (int i = 0; i < numSubsets; i++) {
        if (cover[i]) {
            printf("%d ", i);
        }
    }
    printf("\nTotal subsets used: %d\n", coverSize);
}int main() {
    bool subsets[MAX_SUBSETS][MAX_ELEMENTS] = {
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1}};
    setCover(subsets, 5, 10);
    return 0;
}