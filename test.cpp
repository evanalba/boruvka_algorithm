#include "boruvka_algorithm.h"
#include <gtest/gtest.h>

// vector<int> x = {10, 100, 1000, 10000, 100000, 500000};

TEST(MST, EmptyGraph) {
    std::vector<Edge> edges;
    const int total_vertices = 0;
    const int expected_weight = 0;
    EXPECT_EQ(0, boruvka(edges, 0));
    EXPECT_EQ(0, kruskal(edges, 0));
    std::vector<std::vector<int>> graph;
    EXPECT_EQ(0, prim(graph, 0));
}

TEST(MST, SingleVertexGraph) {
    std::vector<Edge> edges;
    const int total_vertices = 1;
    const int expected_weight = 0;
    EXPECT_EQ(0, boruvka(edges, 0));
    EXPECT_EQ(0, kruskal(edges, 0));
    std::vector<std::vector<int>> graph;
    EXPECT_EQ(0, prim(graph, 0));
}

TEST(MST, DisconnectedGraph) {
    std::vector<Edge> edges = {
        {0, 1, 10},
        {2, 3, 20},
    };
    std::vector<std::vector<int>> graph = {{0, 10, 0, 0},
                                           {10, 0, 0, 0},
                                           {0, 0, 0, 20},
                                           {0, 0, 20, 0}};
    const int total_vertices = 4;
    const int expected_weight = 30;
    EXPECT_EQ(expected_weight, boruvka(edges, total_vertices));
    EXPECT_EQ(expected_weight, kruskal(edges, total_vertices));
    EXPECT_EQ(10, prim(graph, total_vertices));
}

TEST(MST, CompleteGraph) {
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
    std::vector<std::vector<int>> graph = {{0, 5, 7, 0, 0, 0},
                                           {5, 0, 2, 0, 0, 3},
                                           {7, 2, 0, 3, 4, 2},
                                           {0, 0, 3, 0, 3, 0},
                                           {0, 0, 4, 3, 0, 2},
                                           {0, 3, 2, 0, 2, 0}};
    const int total_vertices = 6;
    const int expected_weight = 14;
    EXPECT_EQ(expected_weight, boruvka(edges, total_vertices));
    EXPECT_EQ(expected_weight, kruskal(edges, total_vertices));
    EXPECT_EQ(expected_weight, prim(graph, total_vertices));
}

// TEST(BoruvkaTest, RandomGraph) {
//   // Replace with your function to generate random graphs with n vertices and m edges
//   auto random_graph = GenerateRandomGraph(10, 15);

//   int total_vertices = random_graph.first;
//   std::vector<Edge> edges = random_graph.second;

//   auto mst = Boruvka(edges, total_vertices);
//   EXPECT_TRUE(mst.weight >= 0);  // Weight should not be negative
//   // You can add additional assertions based on your MST properties
// }
