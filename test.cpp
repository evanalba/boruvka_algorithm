#include "boruvka_algorithm.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MST, GetMinWeight) {
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
    EXPECT_EQ(14, boruvka(edges, 6));
    EXPECT_EQ(14, kruskal(edges, 6));
    std::vector<std::vector<int>> graph = {{0, 5, 7, 0, 0, 0},
                                           {5, 0, 2, 0, 0, 3},
                                           {7, 2, 0, 3, 4, 2},
                                           {0, 0, 3, 0, 3, 0},
                                           {0, 0, 4, 3, 0, 2},
                                           {0, 3, 2, 0, 2, 0}};
    EXPECT_EQ(13, prim(graph, 6));
    //vector<int> x = {10, 100, 1000, 10000, 100000, 500000};

}