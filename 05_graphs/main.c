#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

void print_path(graph_node *destination);

int main(){

    double mat[6][6] = {{-1,10,18,8,-1,-1},{10,-1,16,9,21,-1},{-1,16,-1,-1,15,-1},{7,9,-1,-1,-1,12},{-1,-1,-1,-1,-1,23},{-1,-1,15,-1,23,-1}};
    //double mat[6][6] = {{-1,1,5,-1,-1,-1},{-1,-1,-1,-1,-1,15},{-1,-1,-1,2,-1,-1},{-7,-9,-1,-1,1,-12},{-1,-1,-1,-1,-1,3},{-1,-1,-15,-1,-23,-1}};
    double **adjmat = (double **) calloc(6, sizeof(double *));
    size_t i;
    for (i = 0; i < 6; ++i)
	adjmat[i] = (double *) calloc(6, sizeof(double));

    size_t j;
    for (i = 0; i < 6; ++i)
	for (j = 0; j < 6; ++j)
	    adjmat[i][j] = mat[i][j];
    
#ifdef ARRAY
    graph_node *result = array_dijkstra((double **) adjmat, 6, 0);
#else 
    graph_node *result = heap_dijkstra((double **) adjmat, 6, 0);
#endif

    for (i = 0; i < 6; ++i){
	printf("Node %lu distance: %lf\nPath: ", i+1, result[i].d);
	print_path(&result[i]);
    }

    for (j = 0; j < 6; ++j)
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
