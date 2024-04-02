#include "../boruvka_algorithm.cpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    const int total_vertices = 10;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> graph(total_vertices, std::vector<int>(total_vertices, 0));

    std::ifstream infile("ba10_0.edgelist");
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int node1, node2, weight;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!(iss >> node1 >> node2)) {
            std::cerr << "Error reading edge data!" << std::endl;
            continue;
        }

        if (iss >> weight) {
            // std::cout << "Edge: " << node1 << " -> " << node2 << " (weight: " << weight << ")" << std::endl;
            edges.push_back({node1, node2, weight});
            graph[node1][node2] = weight;
            graph[node2][node1] = weight;
        } else {
            std::cerr << "No weight present in file!" << std::endl;
            return 1;
        }
    }

    infile.close();

    boruvka(edges, total_vertices);
    std::cout << std::endl;
    kruskal(edges, total_vertices);
    std::cout << std::endl;
    prim(graph, total_vertices);
    std::cout << std::endl;
    
    // Print the 2d graph.
    for (int i = 0; i < total_vertices; i++) {
        for (int j = 0; j < total_vertices; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}