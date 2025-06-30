#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minCoins(int amount, const vector<int>& coins) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=amount; i++) {
        for(int coin : coins) {
            if(coin <= i) {
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}
int main() {
    int amount = 8;
    vector<int> coins = {1, 4, 6};
    int min_coins = minCoins(amount, coins);
    if(min_coins == -1) {
        cout << "Impossible to make the amount with given coins\n";
    } else {
        cout << "Minimum number of coins required: " << min_coins << endl;
    }
    return 0;
}