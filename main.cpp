#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

struct Edge {
    int source, destination, weight;
};

struct Node {
    int parent, rank;
};

// Sort edges by weight in ascending order.
bool compare_weights(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Function to find_set the Node of an element using path compression.
int find_set(Node vertex[], int i) {
    if (vertex[i].parent != i) {
        vertex[i].parent = find_set(vertex, vertex[i].parent);
    }
    return vertex[i].parent;
}

// Function to perform union of two vertex using union by rank
void union_sets(Node vertex[], int x, int y) {
    int xroot = find_set(vertex, x);
    int yroot = find_set(vertex, y);
    if (vertex[xroot].rank < vertex[yroot].rank)
        vertex[xroot].parent = yroot;
    else if (vertex[xroot].rank > vertex[yroot].rank)
        vertex[yroot].parent = xroot;
    else {
        vertex[yroot].parent = xroot;
        vertex[xroot].rank++;
    }
}

void boruvka(std::vector<Edge> edges, int total_vertices) {
    std::vector<Edge> mst;
    int MSTWeight = 0;

    Node *vertex = new Node[total_vertices];
    int *lowest_edge = new int[total_vertices];

    for (int id = 0; id < total_vertices; id++) {
        vertex[id].parent = id;
        vertex[id].rank = 0;
        lowest_edge[id] = INT_MAX;
    }

    // Keep combining components until all components are in one tree
    int numTrees = total_vertices;
    while (numTrees > 1) {

        // Find Lowest Edge
        for (int i = 0; i < edges.size(); i++) {
            int set1 = find_set(vertex, edges[i].source);
            int set2 = find_set(vertex, edges[i].destination);

            if (set1 != set2) {
                if ((lowest_edge[set1] == INT_MAX) ||
                    (edges[lowest_edge[set1]].weight > edges[i].weight)) {
                    lowest_edge[set1] = i;
                }

                if ((lowest_edge[set2] == INT_MAX) ||
                    (edges[lowest_edge[set2]].weight > edges[i].weight)) {
                    lowest_edge[set2] = i;
                }
            }
        }

        for (int v = 0; v < total_vertices; v++) {
            if (lowest_edge[v] != INT_MAX) {
                int set1 = find_set(vertex, edges[lowest_edge[v]].source);
                int set2 = find_set(vertex, edges[lowest_edge[v]].destination);

                if (set1 != set2) {
                    mst.push_back(edges[lowest_edge[v]]);
                    MSTWeight += edges[lowest_edge[v]].weight;
                    union_sets(vertex, set1, set2);
                    numTrees--;
                }

                lowest_edge[v] = -1;
            }
        }
    }

    std::cout << "Boruvka's Minimum Spanning Tree Weight: " << MSTWeight << std::endl;
    std::cout << "Selected Edges:" << std::endl;
    for (const Edge &edge : mst) {
        std::cout << edge.source << " -- " << edge.destination << " \tWeight: " << edge.weight << std::endl;
    }

    delete[] vertex;
    delete[] lowest_edge;
}

void kruskal(std::vector<Edge> &edges, int total_vertices) {
    std::vector<Edge> mst;
    int MSTWeight = 0;

    Node *vertex = new Node[total_vertices];
    for (int id = 0; id < total_vertices; id++) {
        vertex[id].parent = id;
        vertex[id].rank = 0;
    }

    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), compare_weights);

    for (Edge e : sortedEdges) {
        int set1 = find_set(vertex, e.source);
        int set2 = find_set(vertex, e.destination);
        if (set1 != set2) {
            mst.push_back(e);
            MSTWeight += e.weight;
            union_sets(vertex, set1, set2);
        }
    }
    std::cout << "Kruskal's Minimum Spanning Tree Weight: " << MSTWeight << std::endl;
    std::cout << "Selected Edges:" << std::endl;
    for (const Edge &edge : mst) {
        std::cout << edge.source << " -- " << edge.destination << " \tWeight: " << edge.weight << std::endl;
    }

    delete[] vertex;
}

int main() {
    int V = 6;
    int E = 9;
    std::vector<Edge> edges = {
        {0, 1, 5},
        {0, 2, 7},
        {1, 2, 2},
        {1, 5, 3},
        {2, 5, 2},
        {5, 4, 2},
        {2, 3, 3},
        {2, 4, 4},
        {3, 4, 3}};

    std::vector<Edge> graph;

    boruvka(edges, V);
    std::cout << std::endl;
    kruskal(edges, V);

    return 0;
}