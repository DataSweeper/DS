#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"
int
main(int argc, char **argv)
{
    Counter c;
    int value;
    c = counterCreate();
    initCounter(c);
    while((value = counterIncrement(c)) < 10) {
	printf("%d\n", value);
    }

    counterDestroy(c);

    return 0;
}
