CC= gcc
CCFLAGS= -Wall -Wextra
searching= search_test.x 
sorting= sorting_test.x
SEARCH_FILES= search_algorithms.c
SORT_FILES= sorting_algorithms.c ../04_heap/heaps.c
DEV_FLAGS = -ggdb

all: ${searching} ${sorting}

sort : ${sorting}

search : ${searching}

${searching} : ${searching:x=c} ${MATRIX_AUX} ${SEARCH_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS}


${sorting}: ${sorting:x=c} ${MATRIX_AUX} ${SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS}


clean:
	rm *.x
.PHONY: clean all
