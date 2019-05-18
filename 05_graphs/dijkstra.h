#ifndef WEIGHTED_GRAPHS_H
#define WEIGHTED_GRAPHS_H

#include <stdlib.h> 

struct g_node {
    size_t id;
    size_t pos;
    double d;
    struct g_node *prev;
};
typedef struct g_node graph_node;

graph_node *array_dijkstra(double **adj_matrix, const size_t n, const size_t source );
graph_node  *heap_dijkstra(double **adj_matrix, const size_t n, const size_t source );

#endif
