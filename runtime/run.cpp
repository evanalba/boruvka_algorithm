#include "boruvka_runtime.cpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    // Change total number of vertices here!
    const int total_vertices = 100;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> graph(total_vertices, std::vector<int>(total_vertices, 0));

    // Change filename here!
    std::ifstream infile("ba100_0.edgelist");
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
            // Testing...
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
    std::cout << "Total Vertices: " << total_vertices << std::endl
              << std::endl;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    double elapsed = -1;

    std::cout << "Boruvka's algorithm:" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    boruvka(edges, total_vertices);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    std::cout << "Time elapsed: " << elapsed << std::endl
              << std::endl;

    std::cout << "Kruskal's algorithm:" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    kruskal(edges, total_vertices);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    std::cout << "Time elapsed: " << elapsed << std::endl
              << std::endl;

    std::cout << "Prim's algorithm:" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    prim(graph, total_vertices);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    std::cout << "Time elapsed: " << elapsed << std::endl
              << std::endl;

    // TESTING: Print the 2d graph.
    // for (int i = 0; i < total_vertices; i++) {
    //     for (int j = 0; j < total_vertices; j++) {
    //         std::cout << graph[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}
