#ifndef _SERACH_ALGS_H_
#define _SERACH_ALGS_H_

#ifndef ELEMENT_TYPE
#define	ELEMENT_TYPE int
#endif

#include <stdlib.h>

size_t linear_search (ELEMENT_TYPE *items, size_t n, ELEMENT_TYPE query);
size_t binary_search (ELEMENT_TYPE *items, size_t n, ELEMENT_TYPE query);

#endif
