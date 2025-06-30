#include <iostream>
#define MAX_SIZE 6
int M[MAX_SIZE][MAX_SIZE];
void computeM(int sequence[], int n) {
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            M[i][j] = 0;
        }
    }
    for(int i=0; i<n-1; i++) {
        int dim1 = sequence[i];
        int dim2 = sequence[i+1];
        M[i][i+2] = dim1 * dim2;
    }
}
int main() {
    int sequence[] = {4, 10, 3, 12, 20, 7};
    int n = sizeof(sequence) / sizeof(sequence[0]);
    computeM(sequence, n);
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}