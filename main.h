#ifndef MAIN_H
#define MAIN_H
#include <algorithm>
#include <iostream>
#include <vector>
struct Edge {
    int source, destination, weight;
};
struct Node {
    int parent, rank;
    void set_key(int key) {
        rank = key;
    }
    int get_key() {
        return rank;
    }
};
bool compare_weights(const Edge &a, const Edge &b);
int find_set(Node vertex[], int i);
void union_sets(Node vertex[], int x, int y);
void boruvka(std::vector<Edge> edges, int total_vertices);
void kruskal(std::vector<Edge> edges, int total_vertices);
#endif