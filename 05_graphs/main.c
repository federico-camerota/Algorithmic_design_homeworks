#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    double mat[6][6] = {{-1,10,18,8,-1,-1},{10,-1,16,9,21,-1},{-1,16,-1,-1,15,-1},{7,9,-1,-1,-1,12},{-1,-1,-1,-1,-1,23},{-1,-1,15,-1,23,-1}};
    double **adjmat = (double **) calloc(6, sizeof(double *));
    size_t i;
    for (i = 0; i < 6; ++i)
	adjmat[i] = (double *) calloc(6, sizeof(double));

    size_t j;
    for (i = 0; i < 6; ++i)
	for (j = 0; j < 6; ++j)
	    adjmat[i][j] = mat[i][j];
    

    graph_node *result = array_dijkstra((double **) adjmat, 6, 0);

    for (i = 0; i < 6; ++i)
	printf("Node %lu distance: %lf\n", i, result[i].d);

    free(result);
}
