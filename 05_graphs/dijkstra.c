#include "dijkstra.h"
#include "../04_heap/heaps.h"
#include <float.h>
#include <stdlib.h>

//////////////////
// ARRAY DIJKSTRA
//////////////////
    void init_array (graph_node *node_array, const size_t n, const size_t source);
    void relax (graph_node *node_array, const size_t u, const size_t v, const double w);
    size_t get_min_node (graph_node **node_array, const size_t n);

    graph_node *array_dijkstra(double **adj_matrix, const size_t n, const size_t source ){

	graph_node *nodes = (graph_node *) calloc(n, sizeof(graph_node));
	init_array(nodes, n, source);
	graph_node *nodes_index[n];
	size_t index_size = n;
	size_t i;
	for (i = 0; i < n; ++i)
	    nodes_index[i] = &(nodes[i]);

	size_t min = source;
	nodes_index[source] = nodes_index[index_size - 1];
	while (min != index_size){
	
	    size_t i;
	    for (i = 0; i < n; ++i){
	    
		if (i != min && adj_matrix[min][i] >= 0)
		    relax(nodes, min, i, adj_matrix[min][i]);
	    }

	    index_size--;
	    min = get_min_node(nodes_index, index_size);
	    nodes_index[min]= nodes_index[index_size - 1];
	}
	return nodes;
    }


    void init_array (graph_node *node_array, const size_t n, const size_t source){

	size_t i;
	for (i = 0; i < n; ++i){
	
	    node_array[i].prev = NULL;
	    node_array[i].d = (i == source) ? 0 : DBL_MAX;
	    node_array[i].id = i;
	}
    }

    void relax (graph_node *node_array, const size_t u, const size_t v, const double w){

	if (node_array[u].d + w < node_array[v].d){
	
	    node_array[v].d = node_array[u].d + w;
	    node_array[v].prev = &(node_array[u]);
	}
    }

    size_t get_min_node (graph_node **node_array, const size_t n){

	size_t min_idx = n;
	double min_val = DBL_MAX;

	size_t i;
	for ( i = 0; i < n; ++i){
	
	    if ((node_array[i])->d < min_val)
		min_idx = i;
	}

	return (min_idx != n) ? node_array[min_idx]->id : n;
    }
