CC= gcc
CCFLAGS= -Wall -Wextra -lm
searching= search_test.x 
sorting= sorting_test.x
linear_sorting= linear_sorting_test.x
SEARCH_FILES= search_algorithms.c
SORT_FILES= sorting_algorithms.c ../04_heap/heaps.c
LINEAR_SORT_FILES= linear_sorting.c ../04_heap/heaps.c sorting_algorithms.c
DEV_FLAGS = -ggdb

all: ${searching} ${sorting} ${linear_sorting}

sort : ${sorting}

linear_sort : ${linear_sorting}

search : ${searching}



${searching} : ${searching:x=c} ${MATRIX_AUX} ${SEARCH_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS}


${sorting}: ${sorting:x=c} ${MATRIX_AUX} ${SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS} 

${linear_sorting}: ${linear_sorting:x=c} ${MATRIX_AUX} ${LINEAR_SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS} -DELEMENT_TYPE=double

clean:
	rm *.x
.PHONY: clean all
