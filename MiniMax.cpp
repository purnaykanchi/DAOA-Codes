#include <bits/stdc++.h>
using namespace std;

struct MinMax {
    int min, max;
};

struct MinMax findMinMax(int arr[], int n) {
    struct MinMax result;
    int i;
    
    if (n == 1) {
        result.min = arr[0];
        result.max = arr[0];
        return result;
    }
    
    if (arr[0] > arr[1]) {
        result.max = arr[0];
        result.min = arr[1];
    } else {
        result.max = arr[1];
        result.min = arr[0];
    }
    
    i = 2;
    while (i < n-1) {
        if (arr[i] > arr[i+1]) {
            if (arr[i] > result.max)
                result.max = arr[i];
            if (arr[i+1] < result.min)
                result.min = arr[i+1];
        } else {
            if (arr[i+1] > result.max)
                result.max = arr[i+1];
            if (arr[i] < result.min)
                result.min = arr[i];
        }
        i += 2;
    }
    
    if (i == n-1) {
        if (arr[i] > result.max)
            result.max = arr[i];
        else if (arr[i] < result.min)
            result.min = arr[i];
    }
    
    return result;
}

int main() {
    int arr[] = {50, 40, -5, -9, 45, 90, 65, 25, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct MinMax result = findMinMax(arr, n);
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    return 0;
}