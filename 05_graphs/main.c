#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

void print_path(graph_node *destination);

int main(){

    /*
     * The following matrix is the one used in the example found at: 
     * https://assignment.essayshark.com/blog/dijkstras-shortest-path-algorithm-example/
     */
    double mat[6][6] = {{-1,10,18,8,-1,-1},{10,-1,16,9,21,-1},{-1,16,-1,-1,15,-1},{7,9,-1,-1,-1,12},{-1,-1,-1,-1,-1,23},{-1,-1,15,-1,23,-1}};
    /*
     * The following matrix is the one used in the example showed in class
     */
    //double mat[6][6] = {{-1,1,5,-1,-1,-1},{-1,-1,-1,-1,-1,15},{-1,-1,-1,2,-1,-1},{-7,-9,-1,-1,1,-12},{-1,-1,-1,-1,-1,3},{-1,-1,-15,-1,-23,-1}};
    /*
     * The following matrix is the one used in the example at page 596 of "Introduction to Algorithmss" 2ed, assigning the following ids to the nodes:
     * s = 1, t = 2, x = 3, z = 4, y = 5
     */
    //double mat[5][5] = {{-1, 10, -1, -1, 5}, {-1, -1, 1, -1, 2}, {-1, -1, -1, 4, -1}, {7, -1, 6, -1, -1}, {-1, 3, 9, 2, -1}};
    size_t n = 6;
    double **adjmat = (double **) calloc(n, sizeof(double *));
    size_t i;
    for (i = 0; i < n; ++i)
	adjmat[i] = (double *) calloc(n, sizeof(double));

    size_t j;
    for (i = 0; i < n; ++i)
	for (j = 0; j < n; ++j)
	    adjmat[i][j] = mat[i][j];
    
#ifdef ARRAY
    graph_node *result = array_dijkstra((double **) adjmat, n, 0);
#else 
    graph_node *result = heap_dijkstra((double **) adjmat, n, 0);
#endif

    for (i = 0; i < n; ++i){
	printf("Node %lu distance: %lf\nPath: ", i+1, result[i].d);
	print_path(&result[i]);
    }

    for (j = 0; j < n; ++j)
	free(adjmat[j]);
    free(adjmat);
    free(result);
}

void print_path(graph_node *destination){

    printf("%lu", destination->id + 1);
    destination = destination->prev;
    while (destination != NULL){
	
       printf(" - %lu", destination->id + 1);
	destination = destination->prev;       
    }
    putchar('\n');
}
