#ifndef WEIGHTED_GRAPHS_H
#define WEIGHTED_GRAPHS_H

#include <stdlib.h> 

/*
 * This struct represents a node in the graph
 * - the id member is the number associated with each node
 * - the pos member is the position of the node in the queue
 *   used in the dijskra algorithm (for the array based version
 *   this is equal to the id)
 * - the d member is the distance from the source node
 * - the prev member is a pointer to the previous node
 *   in the shortest path from the source to this node.
 *
 *   A node that cannot be reached from the source node will 
 *   have distance set to DBL_MAX and previous node set to
 *   NULL.
 */
struct g_node {
    size_t id;
    size_t pos;
    double d;
    struct g_node *prev;
};
typedef struct g_node graph_node;

/*
 * Array and heap based versions of the dijksra's algorithm
 * Both versions return an array of graph_nodes representing all the nodes
 * in the graph.
 *
 * adj_matrix is the adjacency matrix describing the graph
 * n is the number of nodes in the graph
 * source is the id of the source node from which shortest paths are to be computed
 */
graph_node *array_dijkstra(double **adj_matrix, const size_t n, const size_t source );
graph_node  *heap_dijkstra(double **adj_matrix, const size_t n, const size_t source );

#endif
