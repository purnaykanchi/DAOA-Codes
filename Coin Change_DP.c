#include<stdio.h>
int minCoins(int coins[], int n, int amount) {
    int dp[amount+1];
    for(int i=0; i<=amount; i++)
        dp[i] = amount+1;
    dp[0] = 0;
    for(int i=1; i<=amount; i++) {
        for(int j=0; j<n; j++) {
            if(coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if(sub_res != amount+1 && sub_res+1 < dp[i])
                    dp[i] = sub_res+1;
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main() {
    int coins[] = {1, 4, 6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 8;
    int min_coins = minCoins(coins, n, amount);
    if(min_coins != -1)
        printf("Minimum number of coins required to make %d: %d\n", amount, min_coins);
    else
        printf("It is not possible to make %d using given coins.\n", amount);
    return 0;
}