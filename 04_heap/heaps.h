#ifndef HEAPS_H
#define HEAPS_H

#ifndef ITEM_TYPE
#define ITEM_TYPE int
#endif

//Declaration of the binary_heap struct
typedef struct {
    size_t max_size = 0;
    size_t current_size = 0;
    ITEM_TYPE *items = NULL;
} binary_heap;


#endif
