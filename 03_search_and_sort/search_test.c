#include "search_algorithms.h"
#include <stdio.h>

int main(){

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("Linear search test\n");
    printf("searching 8: %lu\n", linear_search(a,10,8));
    printf("searching 0: %lu\n", linear_search(a,10,0));
    printf("Binary search test\n");
    printf("searching 8: %lu\n", binary_search(a,10,8));
    printf("searching 0: %lu\n", binary_search(a,10,0));
}
