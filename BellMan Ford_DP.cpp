#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int src, dest, weight;
};
class Graph {
    int V, E;
    vector<Edge> edges;
public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }
    void addEdge(int index, int src, int dest, int weight) {
        edges[index] = {src, dest, weight};
    }
    void BellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << " \t\t " << dist[i] << endl;
    }
};
int main() {
    int V = 5;  
    int E = 8;  
    Graph graph(V, E);
    graph.addEdge(0, 0, 1, -1);
    graph.addEdge(1, 0, 2, 4);
    graph.addEdge(2, 1, 2, 3);
    graph.addEdge(3, 1, 3, 2);
    graph.addEdge(4, 1, 4, 2);
    graph.addEdge(5, 3, 2, 5);
    graph.addEdge(6, 3, 1, 1);
    graph.addEdge(7, 4, 3, -3);
    graph.BellmanFord(0);
    return 0;
}