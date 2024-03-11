#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>
struct Edge {
    int source, destination, weight;
};
bool compare_weights(Edge &a, Edge &b);
int find(std::vector<int> &parent, int i);
std::vector<Edge> kruskal(std::vector<Edge> &edges, int vertices);
#endif