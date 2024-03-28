#include "boruvka_algorithm.h"
#include <gtest/gtest.h>

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

TEST(MST, SmallerCompleteGraph) {
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};
    std::vector<std::vector<int>> graph = {{0, 10, 6, 5},
                                           {0, 0, 5, 0},
                                           {6, 0, 0, 4},
                                           {5, 15, 4, 0}};
    const int total_vertices = 4;
    const int expected_weight = 19;

    EXPECT_EQ(expected_weight, boruvka(edges, total_vertices));
    EXPECT_EQ(expected_weight, kruskal(edges, total_vertices));
    EXPECT_EQ(expected_weight, prim(graph, total_vertices));
}
