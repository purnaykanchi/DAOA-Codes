#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    cout << "Coins used:\n";
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            cout << coin << " ";
            count++;
        }
    }
    cout << "\nTotal coins used: " << count << endl;
}int main() {
    vector<int> coins = {1, 5, 10, 25};
    int amount = 67;
    coinChange(coins, amount);
    return 0;
}