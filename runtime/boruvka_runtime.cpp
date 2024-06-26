#include "boruvka_runtime.h"

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

// Uses the disjoint-set data structure
int boruvka(std::vector<Edge> edges, int total_vertices) {
    std::vector<Edge> mst;
    int mst_weight = 0;

    Node *vertex = new Node[total_vertices];
    int *lowest_edge = new int[total_vertices];

    // Set up the nodes as individual components at the start with no
    // knowledge of the lowest weighted edge adjacent to them.
    for (int id = 0; id < total_vertices; id++) {
        vertex[id].parent = id;
        vertex[id].rank = 0;
        lowest_edge[id] = INT_MAX;
    }

    // Keep combining components until all components are processed.
    int numTrees = total_vertices;
    while (numTrees > 1) {

        // Find the Lowest Edge between 2 components.
        for (int i = 0; i < edges.size(); i++) {
            int set1 = find_set(vertex, edges[i].source);
            int set2 = find_set(vertex, edges[i].destination);

            // Make sure the edge does not create a cycle in the process of finding
            // the lowest edge we can connect 2 components with.
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

        // Unite 2 components if possible if we have the lowest edge between
        // them and no cycles.
        bool any_components_merged = false;
        for (int v = 0; v < total_vertices; v++) {
            if (lowest_edge[v] != INT_MAX) {
                int set1 = find_set(vertex, edges[lowest_edge[v]].source);
                int set2 = find_set(vertex, edges[lowest_edge[v]].destination);

                if (set1 != set2) {
                    mst.push_back(edges[lowest_edge[v]]);
                    mst_weight += edges[lowest_edge[v]].weight;
                    union_sets(vertex, set1, set2);
                    any_components_merged = true;
                    numTrees--;
                }

                lowest_edge[v] = -1;
            }
        }

        // If no components were merged in this iteration, the graph is disconnected.
        if (!any_components_merged) {
            break;
        }
    }

    // std::cout << "Boruvka's Minimum Spanning Tree Weight: " << mst_weight << std::endl;
    // std::cout << "Selected Edges:" << std::endl;
    // for (const Edge &edge : mst) {
    //     std::cout << edge.source << " -- " << edge.destination << " \tWeight: " << edge.weight << std::endl;
    // }

    delete[] vertex;
    delete[] lowest_edge;
    return mst_weight;
}

int kruskal(const std::vector<Edge> &edges, int total_vertices) {
    std::vector<Edge> mst;
    int mst_weight = 0;

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
            mst_weight += e.weight;
            union_sets(vertex, set1, set2);
        }
    }
    // std::cout << "Kruskal's Minimum Spanning Tree Weight: " << mst_weight << std::endl;
    // std::cout << "Selected Edges:" << std::endl;
    // for (const Edge &edge : mst) {
    //     std::cout << edge.source << " -- " << edge.destination << " \tWeight: " << edge.weight << std::endl;
    // }

    delete[] vertex;
    return mst_weight;
}

int get_min_key(const std::vector<int> &key, const std::vector<bool> &in_mst) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < key.size(); v++) {
        if (in_mst[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int prim(const std::vector<std::vector<int>> &graph, const int total_vertices) {
    // if (total_vertices == 0) {
    //     std::cout << "\nPrim's Minimum Spanning Tree Weight: 0" << std::endl;
    //     std::cout << "Selected Edges:" << std::endl;
    //     return 0;
    // }

    std::vector<int> mst_parent(total_vertices);
    std::vector<int> key(total_vertices, INT_MAX);
    std::vector<bool> in_mst(total_vertices, false);

    key[0] = 0;
    mst_parent[0] = -1;

    int mst_count = 0;

    while (mst_count < total_vertices) {
        int u = get_min_key(key, in_mst);
        if (u == -1) {
            break;
        }
        in_mst[u] = true;
        mst_count++;

        for (int v = 0; v < total_vertices; v++) {
            if (graph[u][v] && !in_mst[v] && graph[u][v] < key[v]) {
                mst_parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int mst_weight = 0;
    for (int vertex = 0; vertex < total_vertices; vertex++) {
        if (mst_parent[vertex] != -1) {
            mst_weight += graph[mst_parent[vertex]][vertex];
        }
    }

    // std::cout << "Prim's Minimum Spanning Tree Weight: " << mst_weight << std::endl;
    // std::cout << "Selected Edges:" << std::endl;
    // for (int vertex = 1; vertex < total_vertices; vertex++) {
    //     if (mst_parent[vertex] != -1 && graph[mst_parent[vertex]][vertex] != 0) {
    //         std::cout << mst_parent[vertex] << " -- " << vertex << " Weight: " << graph[mst_parent[vertex]][vertex] << std::endl;
    //     }
    // }
    return mst_weight;
}
