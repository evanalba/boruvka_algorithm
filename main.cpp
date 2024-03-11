#include "main.h"

int main() {
    std::cout << "Number of nodes and number of edges: " << std::endl;
    int vertices = -1, edges = -1;
    std::cin >> vertices >> edges;

    std::vector<Edge> graph;
    graph.push_back({0, 1, 2});
    graph.push_back({1, 2, 3});
    graph.push_back({2, 3, 1});
    // for (auto i : graph) {
    //     std::cout << i.source << " ";
    // }

    std::vector<Edge> mst = kruskal(graph, vertices);
     for (auto i : mst) {
        std::cout << i.weight << " ";
    }

    std::cout << std::endl;

    return 0;
}

/* Kruskal's Algorithm */
std::vector<Edge> kruskal(std::vector<Edge> &edges, int vertices) {
    // Sort edges by weight in ascending order
    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), compare_weights);

    // Disjoint-set forest using parent vector
    std::vector<int> parent(vertices);
    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
    }

    std::vector<Edge> mst;
    int numEdges = 0;

    // Process edges from the sorted list
    for (const Edge &edge : sortedEdges) {
        int x = find(parent, edge.source);
        int y = find(parent, edge.destination);

        // If adding the edge does not create a cycle, include it in MST
        if (x != y) {
            mst.push_back(edge);
            parent[y] = x; // Merge sets (can be modified for other strategies)
            numEdges++;
        }

        // Early termination condition: all vertices connected
        if (numEdges == vertices - 1) {
            break;
        }
    }

    // Return the MST edges
    return mst;
}

/* Comparison function for sorting edges by weight (ascending) */
bool compare_weights(Edge &a, Edge &b) {
    return a.weight > b.weight;
}

/* Find the root of a vertex in the disjoint-set forest. */
int find(std::vector<int> &parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}
