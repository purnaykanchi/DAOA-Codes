#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const int INF = 1e6;
struct Edge {
    int u, v, w;
};
void bellmanFordDP(vector<Edge>& edges, int V, int src) {
    vector<vector<int>> dp(V, vector<int>(V, INF));
    dp[0][src] = 0;
    for (int i = 1; i < V; i++) {
        dp[i] = dp[i - 1];  
        for (Edge e : edges) {
            if (dp[i - 1][e.u] + e.w < dp[i][e.v]) {
                dp[i][e.v] = dp[i - 1][e.u] + e.w;
            }
        }
    }
    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int v = 0; v < V; v++) {
        if (dp[V - 1][v] >= INF)
            cout << v << "\tINF\n";
        else
            cout << v << "\t" << dp[V - 1][v] << "\n";
    }
    for (Edge e : edges) {
        if (dp[V - 1][e.u] + e.w < dp[V - 1][e.v]) {
            cout << "Graph contains a negative weight cycle!\n";
            return;
        }
    }int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    bellmanFordDP(edges, V, 0);
    return 0;
}