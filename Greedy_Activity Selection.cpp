#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}
vector<string> activitySelection(vector<vector<int>>& activity) {
    vector<string> ans;
    int time = 0;
    for (int i = 0; i < activity.size(); i++) {
        if (time <= activity[i][1]) {
            ans.push_back("A" + to_string(activity[i][0]));
            time = activity[i][2];
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> activity = {{1, 1, 4}, {2, 2, 4}, {3, 3, 7},{4, 4, 5}, {5, 5, 6}, {6, 6, 8},{7, 7, 10}, {8, 8, 9}};
    sort(activity.begin(), activity.end(), comp);
    vector<string> ans = activitySelection(activity);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}