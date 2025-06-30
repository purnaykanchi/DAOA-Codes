#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int greedyBinPacking(vector<int> items, int capacity) {
    sort(items.rbegin(), items.rend()); 
    vector<int> bins;
    for (int item : items) {
        bool placed = false;
        for (int& bin : bins) {
            if (bin + item <= capacity) {
                bin += item;
                placed = true;
                break;
            }
        }
        if (!placed) bins.push_back(item);
    }
    return bins.size();
}int main() {
    vector<int> weights = {4, 8, 1, 4, 2, 1};
    int bin_capacity = 10;
    cout << "Minimum bins used: " << greedyBinPacking(weights, bin_capacity) << endl;
    return 0;
}