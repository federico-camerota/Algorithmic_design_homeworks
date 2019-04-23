CC= gcc
CCFLAGS= -Wall -Wextra -lm
searching= search_test.x 
sorting= sorting_test.x
linear_sorting= linear_sorting_test.x
select=select_test.x
SEARCH_FILES= search_algorithms.c
SORT_FILES= sorting_algorithms.c ../04_heap/heaps.c
LINEAR_SORT_FILES= linear_sorting.c ../04_heap/heaps.c sorting_algorithms.c
SELECT_FILES= select.c 
DEV_FLAGS = -ggdb

all: ${searching} ${sorting} ${linear_sorting}

sort : ${sorting}

linear_sort : ${linear_sorting}

search : ${searching}

select : ${select}



${searching} : ${searching:x=c} ${SEARCH_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS}


${sorting}: ${sorting:x=c}  ${SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS} 

${linear_sorting}: ${linear_sorting:x=c} ${LINEAR_SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS} -DELEMENT_TYPE=double

${select}: ${select:x=c} ${SELECT_FILES} ${SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS} ${DEV_FLAGS}

clean:
	rm *.x
.PHONY: clean all
