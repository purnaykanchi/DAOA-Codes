#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
struct Graph {
    int V, E;
    vector<pair<int, iPair>> edges;
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w, int x, int y) {
        edges.push_back({w, {u, v}});
    }
};
int kruskalMST();
struct DisjointSets {
    int *parent, *rnk;
    int n;
    DisjointSets(int n) {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++) {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else {
            parent[x] = y;
            if (rnk[x] == rnk[y])
                rnk[y]++;
        }
    }
};
int Graph::kruskalMST() {
    int mst_wt = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    vector<pair<int, iPair>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v) {
            cout << u << " - " << v << endl;
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
}
int main() {
    int V = 5, E = 5;
    Graph g(V, E);
    g.addEdge(0, 1, 3, 0, 0);
    g.addEdge(1, 0, 0, 3, 0);
    g.addEdge(2, 0, 0, 6, 5);
    g.addEdge(0, 3, 6, 0, 4);
    g.addEdge(0, 5, 5, 4, 0);
    cout << "Edges of MST are\n";
    int mst_wt = g.kruskalMST();
    cout << "\nWeight of MST is " << mst_wt;
    return 0;
}