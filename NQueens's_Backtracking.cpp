#include<stdio.h>
#define N_MAX 100
int isSafe(int board[N_MAX][N_MAX], int row, int col, int n) {
    for(int i=0; i<col; i++){
        if(board[row][i] == 1){
            return 0;
    }
}
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return 0;
    }
}
    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j] == 1){
            return 0;
    }
}
    return 1;
}
void printSolution(int board[N_MAX][N_MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}
int solveNQueens(int board[N_MAX][N_MAX], int row, int n) {
    if(row == n) {
        printSolution(board, n);
        return 1;
    }
    for(int col=0; col<n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if(solveNQueens(board, row+1, n)){
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}
int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if(n > N_MAX) {
        printf("Maximum board size is %d\n", N_MAX);
        return 1;
    }
    int board[N_MAX][N_MAX] = {0};
    if(solveNQueens(board, 0, n) == 0) {
        printf("No solution exists\n");
    }
    return 0;
}