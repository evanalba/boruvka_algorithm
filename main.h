#ifndef MAIN_H
#define MAIN_H
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <vector>
struct Edge {
    int source, destination, weight;
};
struct Node {
    int parent, rank;
};
bool compare_weights(const Edge &a, const Edge &b);
int find_set(Node vertex[], int i);
void union_sets(Node vertex[], int x, int y);
void boruvka(std::vector<Edge> edges, int total_vertices);
void kruskal(const std::vector<Edge> &edges, int total_vertices);
int get_min_key(const std::vector<int> &key, const std::vector<bool> &in_mst);
int find_edge(const std::vector<Edge> &graph, int source, int destination);
void print_prim(const std::vector<Edge> &graph, const std::vector<int> &mst_parent, const int total_vertices);
void prim(const std::vector<std::vector<int>>& graph, const int total_vertices);
#endif