#include "heaps.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    size_t N, max;
    max = 20;
    N = 10;
    int *items = (int *) calloc(max, sizeof(int));
    srand(235);
    for (size_t i = 0; i < N; ++i)
	items[i] = rand() % 40;

    binary_heap *heap = bheap_new (items,NULL, max, N);

    for (size_t i = 0; i < N; ++i)
	printf("%d\t",items[i]);
    putchar('\n');
    printf("Is heap: %d\n", bheap_is_heap(heap));

    for (size_t i = 0; i < N; ++i){
	printf("min: %d\n", bheap_remove_min(heap));
	for (size_t i = 0; i < heap->current_size; ++i)
	    printf("%d\t", heap->items[i]);
	putchar('\n');
    }
}
